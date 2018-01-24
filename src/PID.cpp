#include "PID.h"


using namespace std;



/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Kd, double Ki) {
  Kp_ = Kp;
  Kd_ = Kd;
  Ki_ = Ki;  
  

  last_cte_ = 0;
  total_cte_ = 0;

  total_error_ = 0;

  // unused...
  p_error_ = 0;
  d_error_ = 0;
  i_error_ = 0;

}

double PID::GetControlValue(double cte) {
  double cte_diff = cte - last_cte_;
  last_cte_ = cte;
  total_cte_ += cte;

  return  -Kp_ * cte - Kd_ * cte_diff - Ki_ * total_cte_;
}

void PID::UpdateError(double cte) {
  total_error_ += cte * cte;

}

double PID::TotalError(int steps) {
  return total_error_ / steps;
}

void PID::ResetError() {
  total_error_ = 0;
}

void PID::OptimizeParams(int steps) {
  Kp_ += 0.1;
  Kd_ += 5.0;
  Ki_ += 0.001;


}


// DEBUG
void PID::DebugMsg(const std::string& outmsg)  {
  static bool firsttime = true;

  std::ofstream ofile;
  
  if (firsttime) {
    ofile.open("debug.txt");
    firsttime = false;
  }
  else
    ofile.open("debug.txt", std::ios::out | std::ios::app);


  ofile << outmsg << "\r\n";
}