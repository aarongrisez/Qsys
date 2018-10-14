/**Helper functions for the Hamiltonian
* Author: Sam Kagan
*/

#ifndef HAM_HELPER
#define HAM_HELPER

#include <complex>
#include <math.h>

using namespace std;

class HamHelper {
  public:
    HamHelper();
    ~HamHelper();

    static complex<double> identity(complex<double> c){return c;}
    static complex<double> square(complex<double> c){return pow(c,2);}
    static complex<double> cube(complex<double> c){return pow(c,3);}
};

#endif
