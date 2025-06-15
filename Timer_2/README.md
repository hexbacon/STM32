# Timer_2

In this project we go over how to use the Timer to create an PWM signal. We can use this PMW signal to toggel on and off an LED without writing any addition code.

# Getting Started

To get started with this project, you will need to follow these steps:
1. Create a new STM32 project.
2. Confiure the Timer periphereal. In this case we are using the Nucleo F446RE board.
<img src="./Img/Port Overview.png">
3. Configure Timer 4
   - Set the Prescaler to 7999.
   - Set the Period to 1999.
   - We want to get a perfect 1Hz. Our clock is running at 16MHz, we divide it by 8000 to get 2kHz, then we divide it by 2000 to get 1Hz.
<img src="./Img/Timer Config.png">
4. Configure the Output Compare Mode
   - Set the Output Compare Mode to PWM mode 1.
   - Set the Pulse to 1000.
   - This will give us a 50% duty cycle.
   <img src="./Img/PWS Config.png">

5. Output the PWM signal to the pin.

```c
  // Start timer using PWM
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
```
    - This will start the timer and output the PWM signal to the pin.
<img src="./Img/Output Config.png">


# Conclusion
In this project, we have learned how to use the Timer peripheral to create a PWM signal that can toggle an LED on and off without writing any additional code. This is a powerful feature of the STM32 microcontroller that allows for efficient control of peripherals.
