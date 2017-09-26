/** 
 *  @file    main.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright GNU Public License
 *  
 *  @brief ENPM808X, Part of assignment 4
 *
 *  @section DESCRIPTION
 *  
 *  This is a program that tests the PID controller.
 *
 */
#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include "pid.hpp"

/**
 * @brief      Test fixture for pid controller testing.
 */
class PIDTest : public ::testing::Test {
 protected:
    PID obj;  // Create an object to be used in the tests
};

/**
 * @brief      Test for Sanity, just checks whether
 * everything is in order.
 */
TEST_F(PIDTest, SanityCheck) {
  EXPECT_EQ(1, 1);
}

/**
 * @brief      This test is for checking the convergence
 * of the controller. It expects the settling time to be
 * less than 150 milliseconds
 */
TEST_F(PIDTest, convergenceTest) {
  float tolerance = 0.0001;
  float settlingTime = 0.15;
  int numSteps = settlingTime/obj.dt;
  float currentVelocity = 1.0;
  float targetVelocity = 10.0;
  for (int i = 0; i < numSteps; i++) {
    currentVelocity = obj.compute(targetVelocity, currentVelocity);
  }
  EXPECT_NEAR(targetVelocity, currentVelocity, tolerance);
}

/**
 * @brief      The bump test: https://controlstation.com/perform-step-test/
 * Its a common test used in the industry which is comprised of two steps
 * close to one another in opposite directions. The system should be able to
 * settle in the given time limit. Total time limit is 300 milliseconds.
 */
TEST_F(PIDTest, theBumpTest) {
  // This is two steps in opposite directions
  float tolerance = 0.0001;
  float settlingTime = 0.15;
  int numSteps = settlingTime/obj.dt;
  float currentVelocity = 1.0;
  float targetVelocity = 10.0;
  for (int i = 0; i < numSteps; i++) {
    currentVelocity = obj.compute(targetVelocity, currentVelocity);
  }
  targetVelocity = 5.0;
  for (int i = 0; i < numSteps; i++) {
    currentVelocity = obj.compute(targetVelocity, currentVelocity);
  }
  EXPECT_NEAR(targetVelocity, currentVelocity, tolerance);
}
