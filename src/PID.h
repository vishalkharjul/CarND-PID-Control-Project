#ifndef PID_H
#define PID_H
#include "math.h"
#include "iostream"


class PID {
public:
  /*
  * Errors
  */
  double p_error ;
  double i_error ;
  double d_error ;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*No. of steps*/
   int n;

  /*error*/
   double err;

  /*
  Constructor
  */

  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp_, double Ki_, double Kd_);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

    /*
    * Calculate the steer angle using total error.
    */

    double getSteer_value();


    /*
    * Calculate the total PID error.
    */

    double TotalError();

  /*
  * Tune parameters
  */

};

#endif /* PID_H */
