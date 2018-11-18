#include "simulator.hpp"


void Simulator::_register_methods()
{
    godot::register_method("setHamiltonian", &Simulator::_setHamiltonian);
    godot::register_method("setPsi0", &Simulator::_setPsi0);

    godot::register_method("getHamiltonian", &Simulator::_getHamiltonian);
    godot::register_method("getPsi0", &Simulator::_getPsi0);
    godot::register_method("getPropagator", &Simulator::_getPropagator);
    godot::register_method("getCurrentStateSize", &Simulator::_getCurrentStateSize);

    godot::register_method("setSize", &Simulator::_setSize);

    godot::register_method("step", &Simulator::_runOneStep);

}

void Simulator::_setSize(int size){
    _size = size;
}

void Simulator::_setHamiltonian(godot::PoolVector2Array arr){
    _hamiltonian = Eigen::MatrixXcd(_size,_size);
    for(int x = 0; x < arr.size(); ++x){
        godot::Vector2 v =  arr[x];
        _hamiltonian(x) =  std::complex<double>(v.x,v.y);
    }
}

void Simulator::_setPsi0(godot::PoolVector2Array arr){
    _psi0 = Eigen::VectorXcd(_size);
    for(int x = 0; x < arr.size(); ++x){
        godot::Vector2 v = arr[x];
        _psi0(x) = std::complex<double>(v.x,v.y);
    }
    _currentState = Eigen::Vector3cd(_psi0);
}
godot::PoolVector2Array Simulator::_getHamiltonian(){
    godot::PoolVector2Array value;
    for(int x = 0; x < _hamiltonian.size(); ++x){
        auto c =  _hamiltonian(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}
godot::PoolVector2Array Simulator::_getPsi0(){
    godot::PoolVector2Array value;
    for(int x = 0; x < _psi0.size(); ++x){
        auto c =  _psi0(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}
godot::PoolVector2Array Simulator::_getPropagator(){
    godot::PoolVector2Array value;
    for(int x = 0; x < _propagator.size(); ++x){
        auto c = _propagator(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}

int factorial(int n) {
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
	return _propagator.rows();
}

int Simulator::_getPropagatorCols() {
	return _propagator.cols();
}
void Simulator::_setPropagator(Eigen::MatrixXcd temp){
	_propagator = temp.exp();
}

void Simulator::_runOneStep(float delta){
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
