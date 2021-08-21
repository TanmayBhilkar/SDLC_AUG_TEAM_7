/**
 * @file flip_flop.h
 * @author Jayashree.S (jayashree.sr99@gmail.com)
 * @brief Code to get outputs of given flip flop inputs
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __FLIP_FLOP_H__
#define __FLIP_FLOP_H__

#include <stdio.h>
#include <stdlib.h>

/*
 * @brief This function displays the choice menu and asks the use to choose one
 * 
*/
void display(void);

/*
 * @brief Depending on the choice, this function uses switch function to call the respective flip flop
 * 
 * @param character input c from user 
 * @return int 
*/
int option(char c);

/*
 * @brief Function to determine the output of SR Flip Flop
 * 
 * @return int 
*/
int srflipflop();

/*
 * @brief Function to determine the output of JK Flip Flop
 * 
 * @return int 
*/
int jkflipflop();

/*
 * @brief Function to determine the output of D Flip Flop
 * 
 * @return int 
*/
int dflipflop();

/*
 * @brief Function to determine the output of T Flip Flop
 * 
 * @return int 
*/
int tflipflop();

#endif /*__FLIP_FLOP_H__*/

