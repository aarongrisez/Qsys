#include "simulator.hpp"


void Simulator::_register_methods()
{
    godot::register_method("setHamiltonian", &Simulator::_setHamiltonian);
    godot::register_method("SetPsi0", &Simulator::_setPsi0);
    godot::register_method("SetPropigator", &Simulator::_setPropigator);

    godot::register_method("getHamiltonian", &Simulator::_getHamiltonian);
    godot::register_method("getPsi0", &Simulator::_getPsi0);
    godot::register_method("getPropigator", &Simulator::_getPropigator);

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


void Simulator::_setPropigator(godot::PoolVector2Array arr){
    _propagator = Eigen::MatrixXcd(_size,_size);
    for(int x = 0; x < arr.size(); ++x){
        godot::Vector2 v = arr[x];
        _propagator(x) = std::complex<double>(v.x,v.y);
    }
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
godot::PoolVector2Array Simulator::_getPropigator(){
    godot::PoolVector2Array value;
    for(int x = 0; x < _propagator.size(); ++x){
        auto c = _propagator(x); 
        godot::Vector2 v = godot::Vector2(c.real(),c.imag());
        value.append(v);
    }
    return value;
}

void Simulator::_runOneStep(float delta){
    _time += delta;
    Eigen::MatrixXcd temp = _hamiltonian * delta * std::complex<double>(0,-1);

    _propagator =  Eigen::MatrixXcd().Identity(_size,_size);
    for(int i = 1; i < 4; ++i){
        Eigen::MatrixXcd pwr = Eigen::MatrixXcd(temp);
        for(int b = 1; b < i; ++b){
            pwr *= temp;
        }
        _propagator += pwr / ((float)i);
    }
    _currentState = _propagator * _currentState;

}

float Simulator::_getTime(){
    return _time;
}


void Simulator::_init()
{
}