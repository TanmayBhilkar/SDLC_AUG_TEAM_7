# TEST PLAN:

## Table: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|HLT01     | Test various code quality checks | .c files, .out/.exe files,Implementation folder | TBD | TBD | Technical |
|HLT02     | Test various user inputs | User inputs | TBD | TBD | Scenario/Technical|
|HLT03     | Test for various boundary conditions | TBD | TBD | Technical |


## Table: Low level test plan

| **Test ID** | **HLT ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
| LLT01  | HLT01 | Static code analysis | Cppcheck on .c files | TBD | TBD | Technical |
| LLT02  | HLT01 | Dynamic code quality check | Valgrind on .out files | TBD | TBD | Technical |
| LLT03  | HLT02 | Check for wrong input variable for filter choosing | char with wrong code | TBD | TBD | Scenario/Technical |
| LLT04  | HLT03 | Upper and lower limit violation check for freq | Struct with limit violating values of freq | TBD | TBD | Scenario/Technical |