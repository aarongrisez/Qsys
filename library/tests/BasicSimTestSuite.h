#include "cxxtest/TestSuite.h"
#include "../include/basic_sim.h"
#include <complex>
#include <eigen3/Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

class BasicSimTest : public CxxTest::TestSuite {
public:
  void testSim(void) {
    MatrixXcd hamiltonian(3, 3);
    hamiltonian << complex<double>(0.4147272586872562, 0.0), complex<double>(0.2849716083377269, 0.01667585975115329), complex<double>(0.5792858065923596, 0.04493069203570912),
                   complex<double>(0.2849716083377269, -0.01667585975115329), complex<double>(0.17632777798815139, 0), complex<double>(0.44357036381369286, 0.03592326101885296),
                   complex<double>(0.5792858065923596, -0.04493069203570912), complex<double>(0.44357036381369286, -0.03592326101885296), complex<double>(0.7027700178027618, 0);

    int final_time = 3;
    vector<Vector3cd> test_results(3);
    test_results[0] << complex<double>(0,0), complex<double>(0,0), complex<double>(1,0);
    test_results[1] << complex<double>(-0.0004879485178224137,0.005789286784723879), complex<double>(-0.00038701245401623726,0.004433838117152182), complex<double>(0.9999485247388645,0.007027463144540705);
    test_results[2] << complex<double>(-0.001053110413680567,0.011570715146617819), complex<double>(-0.0008295461888506435,0.008863428155216322), complex<double>(0.9997941088170189,0.014053504142851288);


    Vector3cd psi0(3);
    psi0 << complex<double>(0,0), complex<double>(1,0), complex<double>(0,0);

    int DT = 1;
    BasicSim sim(hamiltonian, psi0, DT);
    /*
    TestDataParser test(argv[1]);
    test.parseJson();
    */


    vector<Vector3cd> sim_results = sim.runSim(final_time);
    vector<Vector3cd> actual_results = test_results;//test.get_test_results();

    TS_ASSERT_EQUALS(sim_results.size(), actual_results.size());

    for(int i=0; i<sim_results.size(); ++i) {
        TS_ASSERT(sim_results[i].isApprox(test_results[i]));
    }
  }
};
