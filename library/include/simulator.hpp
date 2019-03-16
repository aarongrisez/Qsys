//
// Created by michaelpollind on 1/11/18.
//

#ifndef QSYS_SIMULATOR_H
#define QSYS_SIMULATOR_H

#include <Godot.hpp>
#include <Reference.hpp>
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
#include <complex>
#include <random>
#include <vector>
#include <map>

class Simulator : public godot::GodotScript<godot::Reference>{
    GODOT_CLASS(Simulator)

private:
    Eigen::MatrixXcd _hamiltonian;
    Eigen::MatrixXcd _propagator;
    Eigen::VectorXcd _psi0;
    Eigen::VectorXcd _currentState;
    std::vector<double> _probabilityDensity;
    void _setPropagator(Eigen::MatrixXcd arr);
    double _time;
    int _size;
    int _result;
    int _sampleProbabilityDensity();
    Eigen::MatrixXcd _getPOVM(std::map<int, int>);
    std::default_random_engine _gen;

public:
    Simulator();
    void _init();
    void _setSize(const int size);
    void _setHamiltonian(godot::PoolVector2Array arr);
    void _setPsi0(godot::PoolVector2Array arr);
    void _runOneStep(float delta);
	int _getCurrentStateSize();
	int _getPropagatorRows();
	int _getPropagatorCols();
    float _getTime();

    godot::String _getErrorMessage();
    godot::PoolRealArray _getProbabilityDensity();
    godot::PoolVector2Array _getHamiltonian();
    godot::PoolVector2Array _getPsi0();
    int _measure();
    godot::PoolVector2Array _getCurrentState();
    godot::PoolVector2Array _getPropagator();

    static void _register_methods();
};

#endif //QSYS_SIMULATOR_H
