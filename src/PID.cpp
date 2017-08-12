#include "PID.h"
#define MIN_NO_STEPS 200

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    n = 0;
    err = 0;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

}

void PID::UpdateError(double cte) {

    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

    n = n +1;
    if(n>MIN_NO_STEPS) //+ .0001*pow(getValue(),2);
    {
        err += pow(cte,2);
    }


}

double PID::getSteer_value()
{
    double steer_angle = -Kp * p_error -Kd * d_error -Ki * i_error;
    if(steer_angle < -1)
    {
        steer_angle = -1;
    }else if(steer_angle > 1)
    {
        steer_angle = 1;
    }

    return steer_angle;
}




double PID::TotalError() {

 return err = err/(n-MIN_NO_STEPS);
}

