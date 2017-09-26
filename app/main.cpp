/** 
 *  @file    main.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright GNU Public License
 *  
 *  @brief ENPM808X, Part of assignment 4
 *
 *  @section DESCRIPTION
 *  
 *  This is a program that regulates the velocity using a PID 
 *  controller. It has one method which computes the next 
 *  velocity given the target and current velocity.
 *
 */

#include "pid.hpp"

/**
 * @brief      Main Function
 *
 * @return     Nothing
 */
int main() {
  PID controller;
  float currentVelocity = 10.0;
  float targetVelocity = 0.0;
  std::cout << "New Velocity: "
    << controller.compute(targetVelocity, currentVelocity)
    << std::endl;
  return 0;
}
