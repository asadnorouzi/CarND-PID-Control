#ifndef PID_H
#define PID_H

#include <vector>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  void Twiddle(double cte);
  void TwiddleParamUpdate(double val, int index);

 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;

  /**
   * PID Coefficients
   */
  double Kp;
  double Ki;
  double Kd;

  double prev_cte;
  double tol;
  double error;
  double best_error;
  int update_steps;
  int eval_steps;
  int max_steps;
  int counter;
  int param_index;
  bool twiddle_add;
  bool twiddle_subtract;
  std::vector<double> dK;
};

#endif  // PID_H
