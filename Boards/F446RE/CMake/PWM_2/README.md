# PWM_2

In this project, we futher built on the previous PWM Project and proceed to utilize muiltime PWM Channels. 

# Getting Started

1. Follow the steps on the [PWM_1](https://github.com/hexbacon/STM32/tree/main/PWM_1) to set up the enviroment.

2. Only difference is to enable multiple PWM Channels on STM32CubeMX.

<img src="./Assets//PWM_2 Setup.png" alt="PWM_2 Setup" width="600" height="400">

3. The code is similar to the previou sproject, only difference is initializing the PWM Channels in the `main.c` file.

```c
  // Init all timers
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
```

```c
uint16_t pwm_value = 0;
  int8_t pwm_change = 1;
  uint32_t now = 0, next_tick = 1000, loop_count = 0, next_change = 0;
  while (1)
  {
    // Get Tick directly
    now = uwTick;
    if(now >= next_tick)
    {
      printf("Tick %lu (loop = %lu)\n", now/1000, loop_count);
      loop_count = 0;
      next_tick = now + 1000;
    }

    if(now >= next_change)
    {
      printf("PWM Value = %lu\n", pwm_value);
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

      next_change = now + 50;
    }
    loop_count++;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```

# Output 

![PWM_2 Output](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExcjZndWs2c3Q0OXp4bjRvMXh2cGhyczluODZybXowdHphc3R0YTYyaiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/ZoooruvZHNvmfKoz1O/giphy.gif)

# Conclusion
In this project, we have successfully implemented multiple PWM channels on the STM32 microcontroller. This allows us to control multiple outputs simultaneously, which can be useful in various applications such as motor control, LED dimming, and more.