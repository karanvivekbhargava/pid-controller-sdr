/** 
 *  @file    pid.cpp
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

#include <pid.hpp>

/**
 * @brief      Constructs the object.
 */
PID::PID() {}

/**
 * @brief      Destroys the object.
 */
PID::~PID() {}

/**
 * @brief      Computes the new velocity
 *
 * @param[in]  targetVelocity   The target velocity
 * @param[in]  currentVelocity  The current velocity
 *
 * @return     returns the new velocity (returns 1.0 for the stub method)
 */
float PID::compute(float targetVelocity, float currentVelocity) {
  // TODO(Sudharshan and Ashish):
  // 1. Find the error from the targetVelocity and the currentVelocity
  // 2. Compute the differential error by using the error from step 1,
  // the error stored in the class variable prevError and the delta time
  // given in class variable dt.
  // 3. Compute the integral error using class variable iError for previous
  // integral errors, error from step 1 and class variable dt.
  // 4. Assign error from step 1 to prevError and integral error from step 3
  // to iError
  // 5. Compute the final responses by using all the errors with class variables
  // Kp, Ki, Kd and currentVelocity.
  float error = targetVelocity - currentVelocity;
  float de = (error - prevError)/dt;
  float di = iError + error*dt;
  prevError = error;
  iError = di;
  return (currentVelocity + Kp*error + Kd*de + Ki*di);
}
