#ifndef __FUN_H__
#define __FUN_H__

/**
 * @brief To prompt the user to enter Binary values
 * 
 * @param number 
 * @return int 
 */
int display(int number);

/**
 * @brief To take user input 
 * 
 * @param arr 
 * @param number 
 * @return int 
 */

int inputs(int *arr,int number);

/**
 * @brief To perform 2 or 3 input Logic AND Gate calculations
 * 
 * @param arr 
 * @param number 
 * @return int 
 */
int ANDgate(int *arr,int number);

/**
 * @brief To perform 2 or 3 input Logic OR Gate calculations
 * 
 * @param arr 
 * @param number 
 * @return int 
 */
int ORgate(int *arr,int number);

/**
 * @brief To perform Logic NOT Gate calculations
 * 
 * @param a 
 * @return int 
 */
int NOTgate(int a);

/**
 * @brief To perform 2 or 3 input Logic NAND Gate calculations
 * 
 * @param arr 
 * @param number 
 * @return int 
 */
int NANDgate(int *arr,int number);

/**
 * @brief To perform 2 or 3 input Logic NOR Gate calculations
 * 
 * @param arr 
 * @param number 
 * @return int 
 */
int NORgate(int *arr,int number);

/**
 * @brief To perform 2 or 3 input Logic XOR Gate calculations
 * 
 * @param arr 
 * @param number 
 * @return int 
 */
int XORgate(int *arr,int number);

/**
 * @brief To perform 2 or 3 input Logic XNOR Gate calculations
 * 
 * @param arr 
 * @param number 
 * @return int 
 */
int XNORgate(int *arr,int number);

#endif

