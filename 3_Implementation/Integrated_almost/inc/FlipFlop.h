/*
 * @file flipflop.h
 * @author Jayashree.S (jayashree.sr99@gmail.com)
 * @brief Code to get outputs of given flip flop inputs
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __FLIPFLOP_H__
#define __FLIPFLOP_H__

#include <stdio.h>
#include <stdlib.h>


/*
 * @brief This function displays the choice menu and asks the use to choose one
 * 
*/
void display_1(void);

/*
 * @brief Depending on the choice, this function uses switch function to call the respective flip flop
 * 
 * @param character input c from user 
 * @return int 
*/
int option(char c);

/*
 * @brief Function to take 3 inputs
 * 
 * @param pointer character input *a,*b,*c from user 
 * @return int 
*/
int input_1(int *a,int *b,int *c);

/*
 * @brief Function to take 2 input
 * 
 * @param pointer character input *a,*b from user 
 * @return int 
*/
int input_2(int *a, int *b);

/*
 * @brief Function to take 1 input
 * 
 * @param pointer character input *a from user 
 * @return int 
*/
int input_3(int *a);

/*
 * @brief Function to give output
 * 
 * @param character input p
 * @return int 
*/
int output(int p);

/*
 * @brief Function to determine the output of SR Flip Flop
 * 
 * @return int 
*/
int srflipflop(int x,int y,int z);

/*
 * @brief Function to determine the output of JK Flip Flop
 * 
 * @return int 
*/
int jkflipflop(int x,int y,int z);

/*
 * @brief Function to determine the output of D Flip Flop
 * 
 * @return int 
*/
int dflipflop(int x);

/*
 * @brief Function to determine the output of T Flip Flop
 * 
 * @return int 
*/
int tflipflop(int x,int z);

#endif /*__FLIP_FLOP_H__*/

