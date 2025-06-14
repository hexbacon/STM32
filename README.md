# STM32 

## NUCLEO-F446RE

This repository contains code for the STM32 NUCLEO-F446RE board, which is based on the STM32F446RE microcontroller. The code is written in C and uses the STM32 HAL library for hardware abstraction. The main purpose is too document my progress on learning the STM32 platform and to provide a reference for future projects.

## What is the NUCLEO-F446RE?
The NUCLEO-F446RE is a development board from STMicroelectronics that features the STM32F446RE microcontroller. It is part of the Nucleo family of boards, which are designed to provide an easy way to develop applications using STM32 microcontrollers. The board includes various peripherals such as LEDs, buttons, and connectors for expansion.

## Features
- STM32F446RE microcontroller with ARM Cortex-M4 core
- 512 KB Flash memory and 128 KB RAM
- USB connectivity
- ST-LINK/V2-1 debugger/programmer
- Arduino Uno V3 connectivity support
- ST morpho headers for easy expansion
- On-board ST MEMS accelerometer
- On-board ST MEMS gyroscope and many more.

## Getting Started
To get started with the NUCLEO-F446RE board, you will need the following:
- A NUCLEO-F446RE board
- A USB cable to connect the board to your computer
- STM32CubeIDE or another compatible IDE for development
- STM32 HAL library for hardware abstraction
- Basic knowledge of C programming and embedded systems

## [Documentation](#documentation)
The documentation for this project is available in the `Documentation` directory. It includes information on regards to the board and its features.

- [STM32F446RE Schematics](Documentation/mb1136-default-c03_schematic.pdf)
- [STM32F446RE Schematics](Documentation/mb1136-default-c04_schematic.pdf)
- [STM32F446RE Documentation](Documentation/stm32f446mc.pdf)
- [STM32F446RE Reference Manual](Documentation/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf)

## Projects

- [Blink_1](Blink_1/README.md) - A simple project that aims to teach how to set up a STM32 CubeIDE project for the STM32 NUCLEO-F446RE board. While this project has code that blinks an LED, however, it does not work and is intentionally left incomplete.
- [Blink_2](Blink_2/README.md) - In this project, we will address the issue found in the previous project, Blink_1, by implementing a more efficient way to blink an LED using timer interrupts. This will allow us to keep the LED blinking without blocking the CPU, enabling it to perform other tasks simultaneously.
- [Blink_Starter](Blink_Starter/README.md) - This project is a simple starter project that demonstrates how to set up a basic STM32 CubeIDE project for the STM32 NUCLEO-F446RE board. It includes basic configurations and a simple LED blinking example.





