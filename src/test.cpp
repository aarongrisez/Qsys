#include <iostream>
#include <Dense>

using namespace std;
using namespace Eigen;

int main() {
  MatrixXd m = MatrixXd::Random(3,3);
  VectorXd v = VectorXd::Random(3);
  cout << "M = " << endl << m << endl;
  cout << "v = " << endl << v << endl;
  cout << "M*v =" << endl << m*v << endl;
}
