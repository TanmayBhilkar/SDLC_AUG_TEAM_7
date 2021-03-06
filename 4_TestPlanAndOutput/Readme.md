# TEST PLAN:

## Table: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|HLT01     | Test various code quality checks | .c files, .out/.exe files,Implementation folder | TBD | TBD | Technical |
|HLT02     | Test various user inputs | User inputs | TBD | TBD | Scenario/Technical|
|HLT03     | Test for various boundary conditions | TBD | TBD | Technical |
|HLT04     | Test for expected and actual design values | Input Parameters | Expected Values | Actual Values | Technical |
|HLT05     | Test  for expected and actual output Voltage| Input Parameters| Expecte Values | Actual Values |  Technical|
## Table: Low level test plan

| **Test ID** | **HLT ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
| LLT01  | HLT01 | Static code analysis | Cppcheck on .c files | TBD | TBD | Technical |
| LLT02  | HLT01 | Dynamic code quality check | Valgrind on .out files | TBD | TBD | Technical |
| LLT03  | HLT02 | Check for wrong input variable for filter choosing | char with wrong code | TBD | TBD | Scenario/Technical |
| LLT04  | HLT03 | Upper and lower limit violation check for freq | Struct with limit violating values of freq | TBD | TBD | Scenario/Technical |
| LLT05  | HLT02 | Oscillators: Check for wrong input variable for oscillator choosing  | char with wrong code | osc_failure (enum) | osc_failure (enum) | Scenario/Technical |
| LLT06  | HLT03 | Oscillators: Upper and lower limit violation check for oscillator frequency, amplitude gain and feedback fraction (one or more) | Structure with limit violating values of oscillator frequency, amplitude gain and feedback fraction (one or more) | osc_limits_error (enum) | osc_limits_error (enum) | Scenario/Technical |
| LLT07  | HLT04 | Oscillators: Circuit Design Parameters Check | Struct with the right input parameters for the given oscillator circuit | Structure containing the expected circuit design parametrs  | Structure containing the calculated circuit design parameters | Technical |
|LLT08   |  HLT05 | Operational Amplifier : check the various output of various Amplifier of voltage output parameter| Rf,Rin,Vin|Vout of different amplifiers|Vout of differnt Amplifier |Technical|
| LLT09 | HLT02 | Logic Gates: Prompt user to choose an option, and number of inputs and check against valid options | char and int | - | - | Scenario based |
| LLT10 | HLT03 | Logic Gates: Prompt for user inputs and check for a valid input | Binary values | Binary values | Binary Values | Scenario based/Technical |
| LLT11 | HLT04 | Logic Gates: If invalid input, display error message | - | - | - | Scenario based/Technical |
| LLT12 | HLT02 | Flip Flops: Prompt user to chooce an option from a menu and check it's validity | char IN A-D or a-d | Respective case execution | Respective case execution | Scenario |
| LLT13 | HLT03 | Flip Flops: Check for various user inputs (within limits) and it's respective output | Calculate Q(next) and return 0 | Calculates Q(next) and returns 0 |  Calculates Q(next) and returns 0 | Scenario |
| LLT14 | HLT04 | Flip Flops: Check for non-binary input | Print "Non-binary value" and return -1 | Prints "Non-binary value" and returns -1 | Prints "Non-binary value" and returns -1 | Scenario |
| LLT15 | HLT04 | Rectifier: Prompt user to enter Vm, Vac in the given range | float  | Respective R,Efficiency | Respective R,Efficiency  | Technical |
| LLT16 | HLT03 | Rectifier: Prompt user to enter Vm in given range (0>Vm && Vm<100) | float  | Vm limits voilated | Vm limits voilated | Technical |
| LLT17 | HLT03 | Rectifier: Prompt user to enter non zero value for Vac  | float  | Vac cant be zero | Vac cant be zero | Technical |
| LLT18 | HLT03 | Rectifier: Prompt user to enter Vac as Vdc/Vac should not be greater than 1 | float  | Vac Limits Voilated | Vac limits voilated | Technical |
| LLT19 | HLT02 | Capacitor: Prompt user to enter no. of capacitors for equivalent capacitance | float | No. of capacitors | Equivalent capacitance | Technical | 
| LLT20 | HLT03 |Capacitor: Prompt user to enter type of combination of capacitors | int | type of combination | Series or parallel | Technical |
