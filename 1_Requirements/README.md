# Requirements
## Introduction
This product is a powerful tool which helps in designing and implementing electronic circuits. It has various components as features like Filters, Oscillators, Amplifiers, Logic gates, etc which are related to electronics. It takes input from the user through Command line and gives the output through the same.

## Research
Many websites were available which would implement only one of the features of our product alone. For example, there are pages or sites for calculating fiters' RC values or implementing logic gates. But we could not find anything integrated to this extent.

## State of Art
### Ageing - Time
 * Usually these type of calculations were done manually, handwritten. Even in colleges, we still practice all these manually. This project is an idea for automating all the calculations and design which will reduce the time consumed and errors committed.
### Ageing - Cost
 * The cost parameter for this project was none. All the softwares and features were freely available on the internet.
 
## 4W&#39;s and 1&#39;H

### Who:
 * Electical,Electronics,control systems,instrumentation engineers and students;people who need to design or use circuits related to electronics.

### What:
 * This project gives out the parameters or the values required to design or implelment the type of electronic component according to the user inputs. 

### When:
 * This project can be used whenever there is a need to implement or design electronic components.

### Where:
 * This project can be used colleges/universities,labs or even for individual uses.

### How:
 * The user can follow the (add link for implementation). Then the user enters their requirements and the output will be displayed.

## SWOT Analysis
![SWOT ANALYSIS](https://github.com/TanmayBhilkar/SDLC_AUG_TEAM_7/blob/main/1_Requirements/SWOT.jpg)


## Features
| Sl. No. | Component | Description |
| ------- | ----------- | ------------- |
| 01 | Design of filters | Taking input like frequency and gain from the user and returning the circuit parameters for design | 
| 02 | OP-AMP |Just to check Wheteher the given parameter forms the given Amplifier or Not. and Find out the output Voltage|
| 03 | Logic Gates | To implement different Logic gates like AND, OR, NOT, NAND, NOR, XOR, and XNOR Gates |  
| 04 | Design of Oscillators | Taking input like oscillating frequency, oscilaltor amplitude gain and feedback fraction from the user and returning the circuit parameters for design of that oscillator circuit |
| 05 | Flip Flops | Implement different Flip Flops and give the next state to the user |
| 06 | Number system conversions | To implement conversion of numbers from one system to the other i.e binary,decimal,octal,hexadecimal |
| 07 | Rectifier | To design different rectifiers by talking input from the user for various parameters |
| 08 | OP-AMP_Part-B |To check Wheteher the given parameter forms the given Amplifier or Not. and Find out the output Voltage|
| 09 | Adders and Subtractors | To implement addition and subtraction on binary numbers|

## High Level Requirements: 
| ID | Description | Status |
| ----- | ----------- | ------- |
| HR01 | Application should implement various electronic component design | TBD |
| HR02 | Application should take input from the user | TBD |
| HR03 | Application should print output to the user | TBD |
| HR04 | Application should work on both Linux and Windows | TBD |
| HR05 | Application should follow clean code rules | TBD |
| HR06 | Op-Amp Application Should Print Voltage to User|TBD|


##  Low level Requirements:
 
| ID | Description | HR ID | Status |
| ------ | --------- | ------ | ----- |
| LR01 | Application should be able to run on the CLI of the user | HR02,HR03 | TBD |
| LR02 | Application should use makefile option for different commands | HR04 | TBD |
| LR03 | Application should comply with different checks like valgrind,cppcheck,build etc. | HR05 | TBD |
| LR04 | Application to be used with a GUI to provide inputs and print outputs | HR02,HR03 | Future |
| LR11 | Application should consider all the different types of active filters available to design | HR01 | TBD |
| LR21 | Implementation of different Logic Gates | HR01 | TBD |
| LR22 | Implement test cases to check the implementation of Logic Gates | HR05 | TBD |
| LR31 | Application should take the Flip Flop present states as input | HR02 | TBD |
| LR32 | Application should print the next state as output | HR03 | TBD |
| LR41 | Application should be able to give an output in specific number system, when user enters an input | HR02,HR03,HR04 | TBD |
| LR51 | Application should be able to give an output of rectifier when user enters input | HR02,HR03 | TBD |
| LR52 | Application should be able to calculate efficiency when user opts for it  | HR02,HR03 | TBD |
| LR53 | Application should be able to take input of Vm in the given range | HR02 | TBD |
| LR60 | Application Should be Able to Take correct Op_AMP| HR06 | TBD|
| LR61 | Application Should Be Able to Give Output According to the Op-Amp| HR06| TBD |
| LR71 | Op-Amp_Part-B Should Print output Voltage by taking inputs for input votages and Resistances| HR02,HR03 |TBD|
| LR72 | Op-Amp_Part-B should give the choice to user to choose various opamps available| HR01 |TBD|
| LR81 | Oscillators, Application should consider the different types of oscillators to design using Op Amp| HR01 |TBD|
| LR82 | Oscillators, Application takes oscillating frequency, oscillator amplitude gain, feedback fraction as inputs depending on the oscillator circuit selected| HR02 |TBD|
| LR83 | Oscillators, Application should print the circuit design parameters of the selected oscillator circuit| HR03 |TBD|
