#include "simulator.hpp"


void Simulator::_register_methods()
{
}

void Simulator::_setHamiltonian(godot::PoolVector2Array& arr){
    _hamiltonian = Eigen::Matrix3cd();
    for(int x = 0; x < arr.size(); ++x){
        godot::Vector2 v =  arr[x];
        _hamiltonian << std::complex<double>(v.x,v.y);
    }
}

godot::PoolVector2Array _getHamiltonian(){
    godot::PoolVector2Array vector2Array;
    vector2Array.resize(9);


    return vector2Array;
}



void Simulator::_init()
{
}