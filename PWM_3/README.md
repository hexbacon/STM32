# PWM_3

In this example, we will use the TIM4 to generate PWM signals on 4 channels. The PWM signal, however the difference is that will produce a square wave with a sine wave modulation. This means that the duty cycle of the PWM signal will change over time, creating a sine wave effect.

# Getting Started

Follow the steps of PWM_2 to set up the project. One small change is that we will use interrupt but a basic setup is enough to run the example.

# Code

1. Define the necessary includes and macros for the project:
```c
  #define SAMPLE_DELAY 10
  #define SAMPLE_FREQUENCY (1000 / SAMPLE_DELAY)
  #define SAMPLE_MID_POINT (SAMPLE_RANGE / 2)
```

2. Define the necessary variables and arrays to hold the PWM channels, angles, and angle changes:
```c
uint32_t led_channel[] = { TIM_CHANNEL_1, TIM_CHANNEL_2, TIM_CHANNEL_3, TIM_CHANNEL_4 };
float angles[] = { 0, 0, 0, 0 };
float angles_changes[] = { 
  1 * (2 * M_PI / SAMPLE_FREQUENCY),
  2 * (2 * M_PI / SAMPLE_FREQUENCY),
  0.5 * (2 * M_PI / SAMPLE_FREQUENCY),
  0.25 * (2 * M_PI / SAMPLE_FREQUENCY)
};
```

3. Define the callback function that will be called when the PWM pulse is finished:
```c
inline void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM4)
  {
    for(uint32_t idx = 0; idx < sizeof(angles) / sizeof(angles[0]); idx++)
      {
        angles[idx] = angles[idx] + angles_changes[idx];
        if(angles[idx] >= 2 * M_PI) angles[idx] -= 2 * M_PI;

        // Update the timer and calculate the sine value
        // The sine value will be between -1 and 1, so we need to scale
        __HAL_TIM_SET_COMPARE(&htim4, led_channel[idx], SAMPLE_MID_POINT - (SAMPLE_MID_POINT * sin(angles[idx])));
      }
  }
  cb_f++;
}

```

4. In the main function, initialize the HAL and configure the system clock:
```c
 // Init all timers
  HAL_TIM_PWM_Start_IT(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start_IT(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start_IT(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start_IT(&htim4, TIM_CHANNEL_4);
```

5. Implement the main loop to handle the PWM signal generation and periodic updates:
```c
uint16_t pwm_value = 0;
  int8_t pwm_change = 1;
  uint32_t now = 0, next_tick = 1000, loop_count = 0, next_change = 0, next_sample = SAMPLE_DELAY;
  while (1)
  {
    // Get Tick directly
    now = uwTick;
    if(now >= next_tick)
    {
      printf("Tick %lu (loop = %lu, callback = %lu)\n", now/1000, loop_count, cb_f);
      loop_count = 0;
      next_tick = now + 1000;
    }

    if(now >= next_sample)
    {
      // Itirate the led_channels
      // On callback function
      next_sample = now + SAMPLE_DELAY;
    }

    /*
    if(now >= next_change)
    {
      //printf("PWM Value = %lu\n", pwm_value);
      // Change the PWM Pulse value
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, pwm_value);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 100-pwm_value);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, pwm_value);
      __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 100-pwm_value);
      // Update pwm_value to current value + pwm_change
      pwm_value += pwm_change;

      // If the pwm is zero, then update the rate to positive 1
      if(pwm_value == 0) pwm_change = 1;
      // If the pwm is 100, then update the rate to negative 1
      if(pwm_value == 100) pwm_change = -1;

      next_change = now + 25;
    }
    */ 
    loop_count++;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```

# Conclusion

In this example, we have successfully generated PWM signals with a sine wave modulation using the TIM4 peripheral. The duty cycle of the PWM signal changes over time, creating a sine wave effect. This can be useful for various applications such as motor control, LED dimming, and audio signal generation. You can further modify the angles and angle changes to create different waveforms or effects as needed. While this is a great example, it is very costly in terms of CPU usage. You can use DMA to reduce the CPU usage and make it more efficient.

# References
- [STM32World Youtube Channel](https://www.youtube.com/watch?v=4s5GswERslA&list=PLVfOnriB1RjWT_fBzzqsrNaZRPnDgboNI&index=14)
