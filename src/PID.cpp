#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  // Previous cte.
  prev_cte = 0.0;

  // Counters.
  counter = 0;
  errorSum = 0.0;
  minError = std::numeric_limits<double>::max();
  maxError = std::numeric_limits<double>::min();
	
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  p_error = cte;

  // Integral error.
  i_error += cte;

  // Diferential error.
  d_error = cte - prev_cte;
  prev_cte = cte;

  errorSum += cte;
  counter++;

  if ( cte > maxError ) {
    maxError = cte;
  }
  if ( cte < minError ) {
    minError = cte;
  }
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return return p_error * Kp + i_error * Ki + d_error * Kd;  // TODO: Add your total error calc here!
}