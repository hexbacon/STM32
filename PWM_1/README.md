# PWM_1

In this project, we explored even futher the capabilities of using timers and generating a PWM Signal with the STM32 Board. Yhe main focus was to generate PWM and programmatically change the pulse width of the signal. 

# Getting Started

1. Follo the steps on the [Gettting Started](https://github.com/hexbacon/STM32/tree/main/Timer_2) from the Timer_2 project to set up the STM32 board.
2. Do not set the pulse width on the CubeMX, we will do it programmatically.
3. Start the PWM signal with the `HAL_TIM_PWM_Start` function.
```c
  printf("Starting board...!\n");
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
```
4. Use the `HAL_TIM_PWM_SetCompare` function to change the pulse width of the PWM signal.
```c
  uint16_t pwm_value = 0;
  int8_t pwm_change = 1;
  uint32_t now = 0, next_tick = 1000, loop_count = 0, next_change = 0;;
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
      
      pwm_value += pwm_change;

      if(pwm_value == 0) pwm_change = 1;
      if(pwm_value == 100) pwm_change = -1;

      next_change = now + 50;
    }
    loop_count++;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
```

# Output Signal 
<video src="./Vid/PWM Ouput.mov" width="640" height="480"  autoplay loop></video>

# Conclusion
In this project, we successfully generated a PWM signal and programmatically changed its pulse width using the STM32 board. The use of timers and the HAL library functions allowed us to control the PWM signal effectively. This project serves as a foundation for further exploration of PWM applications in embedded systems.