/** 
 *  @file    pid.hpp
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

#ifndef PID_HPP_
#define PID_HPP_

#include <iostream>

/**
 * @brief      Class for PID controller.
 */
class PID {
 private:
  float Kp = 0.1, Kd = 0.0001, Ki = 0.00001;
  float prevError = 0.0, iError = 0.0;
 public:
  float dt = 0.001;
  /**
   * @brief      Constructor
   */
  PID();
  /**
   * @brief      Destroys the object.
   */
  ~PID();
  /**
  * @brief      Computes the new velocity
  *
  * @param[in]  targetVelocity   The target velocity
  * @param[in]  currentVelocity  The current velocity
  *
  * @return     returns the new velocity (constant = 1.1)
  */
  float compute(float targetVelocity, float currentVelocity);
};

#endif  // PID_HPP_
