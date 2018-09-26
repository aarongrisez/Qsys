/**Basic tests for Qsys functionality
* Author: Sam Kagan
*/

#include <iostream>
#include <Dense>
#include "HamHelper.h"
#include <complex>
//#include <math.h>
#include <functional>
#include <vector>

using namespace std;
using namespace Eigen;

//MatrixXcd evaluateHammy(vector<function<complex<double>(complex<double>)>> &h, double t);

int main() {
  const float DT = 1/60.0;
  const float SIM_LENGTH = 100;

  //For when the Hamiltonian is of functions of t
  /*
  function<complex<double>(complex<double>)> square = &HamHelper::square;
  vector<function<complex<double>(complex<double>)>> hammy;
  hammy.push_back([](complex<double> y) {return y;});
  hammy.push_back([](complex<double> y) {return pow(y, 2);});
  hammy.push_back([](complex<double> y) {return pow(y, 3);});
  hammy.push_back([](complex<double> y){return sin(y);});
  //H = [t      t^2]
      //[t^3 sin(t)]
  */


  MatrixXcd hamiltonian = MatrixXcd::Random(3,3) * 10;

  MatrixXcd propagator = (-1*DT*hamiltonian).array().exp().matrix();

  VectorXcd psi0 = VectorXcd::Random(3) * 100;

  cout << "H = " << endl << hamiltonian << endl;
  cout << "U = " << endl << propagator << endl << endl;

  VectorXcd psi = psi0;
  for (double i = 0; i < SIM_LENGTH * DT; i+=DT) {
    cout << "At time = " << i << ", psi = " << endl << psi << endl;
    psi = propagator * psi;
    cin.get();
  }
}


/*For when Hamiltonians are of functions of t
///Evaluates the Hamiltonian description  @param h at time @param t
MatrixXcd evaluateHammy(vector<function<complex<double>(complex<double>)>> &h, double t) {
  if (sqrt(h.size()) != floor(sqrt(h.size()))) {
    return MatrixXcd();
  }

  vector<complex<double>> v(h.size(), t)
}
*/
