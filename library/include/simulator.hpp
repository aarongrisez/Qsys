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

class Simulator : public godot::GodotScript<godot::Reference>{
    GODOT_CLASS(Simulator)
private:
    Eigen::MatrixXcd _hamiltonian;
    Eigen::MatrixXcd _propagator;
    Eigen::VectorXcd _psi0;
    Eigen::VectorXcd _currentState;
    void _setPropagator(Eigen::MatrixXcd arr);
    double _time;
    int _size;
public:
    void _init();
    void _setSize(int size);
    void _setHamiltonian(godot::PoolVector2Array arr);
    void _setPsi0(godot::PoolVector2Array arr);
    void _runOneStep(float delta);
	int _getCurrentStateSize();
	int _getPropagatorRows();
	int _getPropagatorCols();
    float _getTime();

    godot::PoolVector2Array _getHamiltonian();
    godot::PoolVector2Array _getPsi0();
    godot::PoolVector2Array _getPropagator();

    static void _register_methods();
};

#endif //QSYS_SIMULATOR_H
