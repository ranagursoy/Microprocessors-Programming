# Microprocessors Experiments and Solar Panel Project

This repository contains seven experiments and one project related to microprocessors and embedded systems. Each experiment focuses on different aspects of microprocessor functionality, while the project involves a light-following mechanism using an LDR (Light Dependent Resistor).

## Table of Contents

- [Experiments](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)
    - [Experiment 1: LED On-Off with Button](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)
    - [Experiment 2: Delay Loops with Button Control](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)
    - [Experiment 3: Timer Interrupt for LED Blinking](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)
    - [Experiment 4: Basic Calculator Using Keypad](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)
    - [Experiment 5: ADC Readings from Potentiometers](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)
    - [Experiment 6: DC Motor Speed and Direction Control](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)
- [Project: Sun Tracking Solar Panel with LDR](https://www.notion.so/Microprocessors-Experiments-and-Solar-Panel-Project-4ee0690f3d0b46c791d3ecf4a77afa16?pvs=21)

## Experiments

### Experiment 1: LED On-Off with Button

**Objective**: Define the input and output pins using assembly language and perform LED on-off control with a button.

**Description**:

- Buttons are connected to the D0 and D2 pins.
- LEDs are connected to the D1 and D3 pins.
- The LED turns on when the corresponding button is pressed, and turns off when the button is released.
- The buttons are connected using different configurations.

### Experiment 2: Delay Loops with Button Control

**Objective**: Implement delay loops using assembly instructions to control the buzzer.

**Description**:

- A button is connected to the D0 pin, and a buzzer is connected to the D1 pin.
- When the button is pressed, the buzzer will turn on and off in 3-second intervals.

### Experiment 3: Timer Interrupt for LED Blinking

**Objective**: Demonstrate the use of interrupt and timer with assembly instructions.

**Description**:

- Using the TMR0 interrupt, the LED connected to the B0 pin will blink at 1-second intervals.

### Experiment 4: Basic Calculator Using Keypad

**Objective**: Create a simple calculator using a keypad to sum two 2-digit numbers.

**Description**:

- The '*' button serves as the function key for addition, and the '#' button works as the execute button.
- Only 2-digit numbers can be entered.
- A warning message will be displayed for 1 second if the input exceeds two digits.
- The result of the addition is shown for 3 seconds before the screen clears.

### Experiment 5: ADC Readings from Potentiometers

**Objective**: Perform ADC (Analog-to-Digital Conversion) readings every 2 seconds using a Timer.

**Description**:

- ADC readings from two potentiometers are displayed on an LCD screen.
- The first reading is shown on the first line, and the second reading on the second line of the LCD.

### Experiment 6: DC Motor Speed and Direction Control

**Objective**: Implement speed and direction control of a DC motor using PWM (Pulse Width Modulation).

**Description**:

- The "Increase" button increases the duty cycle of the PWM signal, speeding up the motor.
- The "Decrease" button reduces the duty cycle, slowing down the motor.
- The "Change Direction" button alternates the motor's direction between clockwise (CW) and counterclockwise (CCW) with each press.

## Project: Sun Tracking Solar Panel with LDR

**Objective**: Design a mechanism that follows light using an LDR sensor.

**Description**:

- The mechanism adjusts based on the light source detected by the LDR.
- The project focuses on the design of the light-tracking mechanism, although a solar panel was not included in the system.