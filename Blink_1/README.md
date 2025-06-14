# Blink_1

In this project, we will create a simple on-board LED. This project shows an incorrect way to use the LED, and then we will fix it on Blink_2.

# Why is it wrong?

There's nothing inherently wrong with the code, but when it comes to optimizing embedded systems, we should always ensure that we are not wasting resources. In the ```main.c``` file, we have the followinf code:

```c
while (1)
  {
    HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin); // Toggles on/off LED PIN
    HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  ```
This code toggles the LED every 500 milliseconds, which is fine for a simple application. However, it uses the HAL_Delay function, which blocks the CPU for 500 milliseconds. This means that during this time, the CPU cannot perform any other tasks, which is not efficient in an embedded system.

# How to fix it?

We will provide the answer in the next project, Blink_2. In that project, we will use a timer interrupt to toggle the LED without blocking the CPU, allowing it to perform other tasks while still keeping the LED blinking.

# Learning

- Understand the limitations of blocking delays in embedded systems.
- Learn how to use timer interrupts to perform tasks without blocking the CPU.
- Gain experience in optimizing embedded code for better performance and resource utilization.

