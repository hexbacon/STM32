# Timer_1

In this project, we will continue our work with blinking an LED, however this time we will explore a timer interrupt to toggle the LED without blocking the CPU, allowing it to perform other tasks while still keeping the LED blinking. We will learn on how to use a timer interrupt and handle interrupt callbacks in STM32.

# Code

```c
 HAL_TIM_Base_Start_IT(&htim4);
 ```

This line starts the timer in interrupt mode. The `HAL_TIM_Base_Start_IT` function initializes the timer and enables its interrupt, allowing the timer to generate periodic interrupts.

```c
// Override callback from interrupt timer
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}
```

This code overrides the `HAL_TIM_PeriodElapsedCallback` function, which is called when the timer period elapses. Inside this function, we toggle the LED pin, allowing it to blink without blocking the CPU.

