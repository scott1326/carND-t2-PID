#ifndef PID_H
#define PID_H

#include <vector>

// DEBUG
#include <fstream>

using namespace std;

class PID {
public:
  /*
  * Errors
  */
  double p_error_;
  double i_error_;
  double d_error_;

  /*
  * Coefficients
  */ 
  double Kp_;
  double Ki_;
  double Kd_;

  /*
  * CTE Totals
  */
  double last_cte_;
  double total_cte_;

  double total_error_;

  std::vector<double> params_;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  *  Get steering
  */
  double GetControlValue(double cte);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError(int steps);

  /*
  * Reset the total error
  */
  void ResetError();

  /*
  * Manually optimize params
  */

  void OptimizeParams(int steps);


  // DEBUG
  //
  //
  void DebugMsg(const std::string&);
};

#endif /* PID_H */
