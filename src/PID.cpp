#include "PID.h"
#include <cmath>
#include <iostream>
#include <limits>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   Kp = Kp_;
   Ki = Ki_;
   Kd = Kd_;

   dK = {1.0, 1.0, 1.0};

   p_error = 0.0;
   i_error = 0.0;
   d_error = 0.0;

   prev_cte = 0.0;
   tol = 0.00001;
   error = 0.0;
   best_error = std::numeric_limits<double>::max();
   update_steps = 100;
   eval_steps = 2000;
   max_steps = 2*update_steps + eval_steps;
   counter = 0;
   param_index = 0;

   twiddle_add = false;
   twiddle_subtract = false;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

   p_error = cte;
   i_error += cte;
   d_error = cte - prev_cte;

   prev_cte = cte;

   Twiddle(cte);
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}

void PID::Twiddle(double cte) {
  if (dK[0] + dK[1] + dK[2] > tol) {
    if (counter % max_steps >  update_steps) {
      error += pow(cte, 2);
    }
    if (counter % max_steps == 0) {
      if (error < best_error) { //optimized values obtained!
        best_error = error;

        if (counter != max_steps) {
          dK[param_index] *= 1.1;
        }
        param_index = (param_index + 1) % dK.size();
        twiddle_add = false;
        twiddle_subtract = false;
      }
      if (!twiddle_add && !twiddle_subtract) {
        TwiddleParamUpdate(dK[param_index], param_index);
        twiddle_add = true;
      } else if (twiddle_add && !twiddle_subtract) {
        TwiddleParamUpdate(-2.0*dK[param_index], param_index);
        twiddle_subtract = true;
      } else {
        TwiddleParamUpdate(dK[param_index], param_index);
        dK[param_index] *= 0.9;
        twiddle_add = false;
        twiddle_subtract = false;
        param_index = (param_index + 1) % dK.size();
      }
      error = 0.0;
      std::cout << "New Optmized Parameters!" << std::endl;
      std::cout << "P = " << Kp << " I = " << Ki << "D = " << Kd << std::endl;
    }
    counter++;
  }
}

void PID::TwiddleParamUpdate(double val, int index) {
  switch (index) {
    case 0:
      Kp += val;
      break;
    case 1:
      Kd += val;
      break;
    case 2:
      Ki += val;
      break;
    default:
      break;
  }
}
