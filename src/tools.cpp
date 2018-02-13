#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;



Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
const vector<VectorXd> &ground_truth) {
  VectorXd rmse(4);
  	rmse << 0,0,0,0;

      // TODO: YOUR CODE HERE

  	// check the validity of the following inputs:
  	//  * the estimation vector size should not be zero
  	//  * the estimation vector size should equal ground truth vector size
  	// ... your code here


    assert(estimations.size() == ground_truth.size());
    if (estimations.size() == 0)
    {
      cout << "WARNING input data has length 0" << endl;
      return rmse;
    }

  	//accumulate squared residuals
  	for(int i=0; i < estimations.size(); ++i){
          // ... your code here
          VectorXd delta = estimations[i] - ground_truth[i];
          VectorXd deltaSq = (delta.array() * delta.array());
          rmse += deltaSq;
  	}

  	rmse = rmse / estimations.size();

  	return rmse.cwiseSqrt();
}

  VectorXd Tools::convert_cartesian_to_polar(const VectorXd& v){

    const double THRESH = 0.001;
    VectorXd polar_vec(3);

    const double px = v(0);
    const double py = v(1);
    const double vx = v(2);
    const double vy = v(3);

    const double rho = sqrt( px * px + py * py);
    const double phi = atan2(py, px); //accounts for atan2(0, 0)
    const double drho = (rho > THRESH) ? ( px * vx + py * vy ) / rho : 0.0;

    polar_vec << rho, phi, drho;
    return polar_vec;
  }

  VectorXd Tools::convert_polar_to_cartesian(const VectorXd& v){

    VectorXd cartesian_vec(4);

    const double rho = v(0);
    const double phi = v(1);
    const double drho = v(2);

    const double px = rho * cos(phi);
    const double py = rho * sin(phi);
    const double vx = drho * cos(phi);
    const double vy = drho * sin(phi);

    cartesian_vec << px, py, vx, vy;
    return cartesian_vec;
  }
