#include <iostream>
#include <eigen3/Eigen/Dense>
#include <complex>


#ifndef BASICSIM_H
#define BASICSIM_H

using namespace std;
using namespace Eigen;

class BasicSim {
  private:
    Matrix3cd hamiltonian;
    Matrix3cd propagator;
    Vector3cd psi0;
    float dt;

  public:
    BasicSim(Matrix3cd hamiltonian, Vector3cd psi0, float dt) {
      this->hamiltonian = hamiltonian;
      this->dt = dt;
      this->propagator = exp(-1*this->hamiltonian.array()).matrix();
      this->psi0 = psi0;
    }

    ~BasicSim(){}

    vector<Vector3cd> runSim(float final_time) {
        vector<Vector3cd> results(final_time/dt);
        Vector3cd psi = psi0;

        for (float i = 0; i < final_time/dt; i+=1) {
          results[i] = psi;
          psi = propagator * psi;
        }

        return results;
    }
};




#endif
