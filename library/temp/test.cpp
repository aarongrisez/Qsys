/**Basic tests for Qsys functionality
* Author: Sam Kagan
*/

#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <complex>
//#include <math.h>
#include <functional>
#include <vector>
#include <string>
#include "../include/json.hpp"

#include "../include/basic_sim.h"

using namespace std;
using namespace Eigen;
using namespace nlohmann;

//MatrixXcd evaluateHammy(vector<function<complex<double>(complex<double>)>> &h, double t);

int main(int argc, char** argv) {
  /*
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

  const float DT = 0.01;
  const float FINAL_TIME = 3*DT;


  Matrix3cd hamiltonian;
  hamiltonian << complex<double>(0.4147272586872562, 0.0), complex<double>(0.2849716083377269, 0.01667585975115329), complex<double>(0.5792858065923596, 0.04493069203570912),
                 complex<double>(0.2849716083377269, -0.01667585975115329), complex<double>(0.17632777798815139, 0), complex<double>(0.44357036381369286, 0.03592326101885296),
                 complex<double>(0.5792858065923596, -0.04493069203570912), complex<double>(0.44357036381369286, -0.03592326101885296), complex<double>(0.7027700178027618, 0);


  vector<Vector3cd> test_results(3);
  test_results[0] << complex<double>(0,0), complex<double>(0,0), complex<double>(1,0);
  test_results[1] << complex<double>(-0.0004879485178224137,0.005789286784723879), complex<double>(-0.00038701245401623726,0.004433838117152182), complex<double>(0.9999485247388645,0.007027463144540705);
  test_results[2] << complex<double>(-0.001053110413680567,0.011570715146617819), complex<double>(-0.0008295461888506435,0.008863428155216322), complex<double>(0.9997941088170189,0.014053504142851288);



  Vector3cd psi0;
  psi0 << complex<double>(0,0), complex<double>(0,0), complex<double>(1,0);
  BasicSim sim(hamiltonian, psi0, DT);
  vector<Vector3cd> sim_results = sim.runSim(FINAL_TIME);


  cout<<endl<<endl;

  if(sim_results.size() == test_results.size()) {
    cout << "The simulation results are the right size!"<<endl<<endl;
  } else {
    cout <<"The simulation results are the wrong size." << endl;
    return -1;
  }


  for(int i=0; i<sim_results.size(); ++i) {
    cout<< "i=" << i<<endl;
    if(sim_results[i].isApprox(test_results[i])) {
      cout << "Simulation result is correct:"<<endl;
      cout<<sim_results[i]<<endl;
    } else {
      cout << "Simulation resulst is INCORRECT:"<<endl;
      cout<<"sim_result = " <<endl<<sim_results[i] <<endl<<"actual_result="<<endl<<test_results[i]<<endl;
    }
    cout<<endl;
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
