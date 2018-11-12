#include "sample.hpp"

void Sample::_register_methods()
{
    godot::register_method("get_data", &Sample::get_data);
}

void Sample::_init()
{
    data = "Hello World from C++";
}

godot::String Sample::get_data() const
{
    return data;
}