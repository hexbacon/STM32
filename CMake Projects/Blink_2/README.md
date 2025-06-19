# Blink_2

In this project, we will address the issue found in the previous project, Blink_1, by implementing a more efficient way to blink an LED using timer interrupts. This will allow us to keep the LED blinking without blocking the CPU, enabling it to perform other tasks simultaneously.

# Solution


```c
uint32_t now = 0, last_blink = 0, last_tick = 0, loop_cnt = 0;
  while (1)
  {
    now = HAL_GetTick();
    if(now - last_blink >= blink_delays[index])
    {
      HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
      last_blink = now;
    }
    if(now - last_tick >= 1000)
    {
      printf("Tick %lu (loop count = %lu)\n", now / 1000, loop_cnt);
    }
    if(btn_pressed == 1)
    {
      //printf("0\n");
      index++;
      if(index > sizeof(blink_delays) / sizeof(blink_delays[0]))
      {
        index = 0;
      }
    
      btn_pressed = 0;
    }
    loop_cnt++;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  ```
This code uses the `HAL_GetTick()` function to get the current time in milliseconds since the system started. It checks if enough time has passed since the last blink and toggles the LED accordingly. This way, the CPU can continue executing other tasks while still managing to blink the LED.

# Why is it better?
This approach is better because it does not block the CPU with a delay function. Instead, it uses a non-blocking method to check the time elapsed since the last blink, allowing the CPU to perform other operations in the meantime. This is crucial in embedded systems where resources are limited and efficiency is key.
