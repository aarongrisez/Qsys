#include "../include/json.hpp"
#include <complex>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace nlohmann;
using namespace Eigen;


#ifndef TEST_DATA_PARSER_H
#define TEST_DATA_PARSER_H

class TestDataParser {
  private:
    string filename;
    json raw_data;
    vector<Vector3cd> test_results;
    complex<double> parse_complex(string s);

  public:
    TestDataParser(string filename);
    ~TestDataParser();
    int parseJson();
    vector<Vector3cd> get_test_results();
};

TestDataParser::TestDataParser(string filename) {
  this->filename = filename;
}

TestDataParser::~TestDataParser(){}

vector<Vector3cd> TestDataParser::get_test_results() {
  return test_results;
}

int TestDataParser::parseJson() {
  ifstream in(filename);

  //File check
  if(!(in &&  in.good()))
  {
    cout<<"Error: Bad file."<<endl<<endl;
    return -1;
  }

  //Read in the JSON file to a JSON object
  in >> raw_data;
  float dt = raw_data["timeStep"];
  int finalTime = raw_data["finalTime"];
  int simLength = dt*finalTime;

  //Read in the test results
  json rawResults = raw_data["simulationData"];
  test_results = vector<Vector3cd>(simLength);
    cout << "Hello?"<<endl;

  for (int i = 0; i<simLength; ++i) {
    cout<<"Row blah of results"<<endl;

    string str = rawResults.at(i);

    str = str.substr(1, str.size() - 2);//Remove the [] from the outside


    size_t pos = 0;
    size_t len = 0;
    Vector3cd result();

    for(int j=0; j<3; ++j) {
      cout<<"Complex number " << j << endl;
      double real = stod(str.substr(pos), &len);
      pos +=len;
      double imag = stod(str.substr(pos), &len);
      pos+=len+2;//To discard the "i,"
      complex<double> cx(real,imag);
      result[j] = cx;
    }

    test_results[i] = result;

    cout<<"\n";
  }
}

#endif
