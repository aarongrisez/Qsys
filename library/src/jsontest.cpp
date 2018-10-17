#include "../include/json.hpp"
#include <complex>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../include/TestDataParser.h"


using namespace std;

int main(int argc, char** argv) {
  TestDataParser test(argv[1]);
  test.parseJson();
  cout << test.get_test_results()[0][0];
}
