/**Basic tests for Qsys functionality
* Author: Sam Kagan
*/

#include <iostream>
#include <fstream>
#include <Dense>
#include "HamHelper.h"
#include <complex>
//#include <math.h>
#include <functional>
#include <vector>
#include <string>
#include "json.hpp"

using namespace std;
using namespace Eigen;
using namespace nlohmann;

//MatrixXcd evaluateHammy(vector<function<complex<double>(complex<double>)>> &h, double t);

int main(int argc, char** argv) {
  const float DT = 1/60.0;
  const float SIM_LENGTH = 100;

  //Take in filename from command line
	//Check for arguments
	if(argc!=2)
	{
		cout<<"Error: Improper number of arguments."<<endl;
		return -1;
	}
	string filename = argv[1];

  //Make sure it's a json file
  if(!(filename.size() > 5 && filename.substr(filename.size() - 5, 5).compare(".json") == 0)) {
    cout<<"Error: File is not a JSON file." << endl << endl;
    return -1;
  }

	ifstream in(filename);

	//File check
	if(!(in &&  in.good()))
	{
		cout<<"Error: Bad file."<<endl<<endl;
		return -1;
	}

  //Read in the JSON file to a JSON object
  json j;
  in >> j;


  //Making sure the test is of the right type
  if(!(j["testType"].is_string() && j["testType"].get<string>().compare(string{"HamiltonianSimulation"}) == 0)) {
    cout << "Error: Test file not of type \"HamiltonianSimulation\"" << endl << endl;
    return -1;
  }

  cout << j["testName"] << endl;

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


  //Read in "hamiltonian" to a MatrixXcd
  //Read in psi0 to a vector
  //Read test data into an array of vectors of complex numbers
  //Read in timeStep and finalTime
  //Run simulation, checking at each stepwhether test[i] = psi (where i is the index of the loop, and time = i*timeStep,
    //so loop terminates when i*timStep >= finalTime).
  //If test[i] != psi, print out the discrepancy with a message and exit.

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
