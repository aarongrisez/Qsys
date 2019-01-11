#include "simulator.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>


void Simulator::_register_methods()
{
    // Exposes internal methods to be called from GDScript
    godot::register_method("setHamiltonian", &Simulator::_setHamiltonian);
    godot::register_method("setPsi0", &Simulator::_setPsi0);
    godot::register_method("getHamiltonian", &Simulator::_getHamiltonian);
    godot::register_method("getPsi0", &Simulator::_getPsi0);
    godot::register_method("getPropagator", &Simulator::_getPropagator);
    godot::register_method("getCurrentStateSize", &Simulator::_getCurrentStateSize);
    godot::register_method("getCurrentState", &Simulator::_getCurrentState);
    godot::register_method("getProbabilityDensity", &Simulator::_getProbabilityDensity);
    godot::register_method("getErrorMessage", &Simulator::_getErrorMessage);
    godot::register_method("measure", &Simulator::_measure);
    godot::register_method("setSize", &Simulator::_setSize);
    godot::register_method("step", &Simulator::_runOneStep);

}

Simulator::Simulator() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    _gen = std::default_random_engine(seed);
}

void Simulator::_setSize(const int size){
    // Sets the size of the system
    _size = size;
}

void Simulator::_setHamiltonian(godot::PoolVector2Array arr){
    // Sets the hamiltonian
    _hamiltonian = Eigen::MatrixXcd(_size,_size);
    for(int x = 0; x < arr.size(); ++x){
        godot::Vector2 v =  arr[x];
        _hamiltonian(x) =  std::complex<double>(v.x,v.y);
    }
}

void Simulator::_setPsi0(godot::PoolVector2Array arr){
    // Sets the initial wavefunction
    _psi0 = Eigen::VectorXcd(_size);
    for(int x = 0; x < arr.size(); ++x){
        godot::Vector2 v = arr[x];
        _psi0(x) = std::complex<double>(v.x,v.y);
    }
    _currentState = Eigen::Vector3cd(_psi0);
}

godot::PoolVector2Array Simulator::_getHamiltonian(){
    // Returns the hamiltonian
    godot::PoolVector2Array value;
    for(int x = 0; x < _hamiltonian.size(); ++x){
        auto c =  _hamiltonian(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}
godot::PoolVector2Array Simulator::_getPsi0(){
    // Returns the initial wavefunction
    godot::PoolVector2Array value;
    for(int x = 0; x < _psi0.size(); ++x){
        auto c =  _psi0(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}
godot::PoolVector2Array Simulator::_getCurrentState(){
    // Returns the current wavefunction
	godot::PoolVector2Array value;
    for(int x = 0; x < _currentState.size(); ++x){
        auto c =  _currentState(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}
godot::PoolVector2Array Simulator::_getPropagator(){
    // Returns the current propagator--translates to row major?
    godot::PoolVector2Array value;
    for(int x = 0; x < _propagator.size(); ++x){
        auto c = _propagator(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}

godot::PoolRealArray Simulator::_getProbabilityDensity() {
    // Returns mod ** 2 of the current state
    // There is some funkiness in this method--Eigen should handle 
    //
    //      v * v.conjugate()
    //
    // just fine, but running in GUT is causing crashes. I resorted
    // to manually running the elementwise vector product instead
    godot::PoolRealArray density;
    std::complex<double> temp;
    _probabilityDensity = std::vector<double>(_size);
    for (int x = 0; x < _size; ++x) {
        temp = _currentState[x] * std::conj(_currentState[x]);
        float c = temp.real();
        _probabilityDensity[x] = c;
        density.append(c);
    }
    return density;
}

int Simulator::_sampleProbabilityDensity() {
    std::discrete_distribution<int> dist(_probabilityDensity.begin(), _probabilityDensity.end());
    return dist(_gen);
}

int Simulator::_measure() {
    _getProbabilityDensity();
    return _sampleProbabilityDensity();
}

int factorial(int n) {
    // Simple factorial implementation -- not needed anymore?
    if (n == 0) {
	return 1;
    }
    else {
	return n * factorial(n - 1);
    }
}

int Simulator::_getCurrentStateSize() {
	return _currentState.size();
}

int Simulator::_getPropagatorRows() {
    // Rename to _getNumPropagatorRows()
	return _propagator.rows();
}

int Simulator::_getPropagatorCols() {
    // Redundant? cols == rows == _size?
	return _propagator.cols();
}

void Simulator::_setPropagator(Eigen::MatrixXcd temp){
	_propagator = temp.exp();
}

void Simulator::_runOneStep(float delta){
    // Applies the propagator once; called each clock cycle
    _time += delta;
    Eigen::MatrixXcd temp = _hamiltonian * delta * std::complex<double>(0,-1);
	_setPropagator(temp);
    _currentState = _propagator * _currentState;
}

float Simulator::_getTime(){
    return _time;
}


void Simulator::_init()
{
}

godot::String Simulator::_getErrorMessage() {
    return _errorMessage;
}
