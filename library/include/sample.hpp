
#ifndef QSYS_SAMPLE_HPP
#define QSYS_SAMPLE_HPP

#include <Godot.hpp>
#include <Reference.hpp>

class Sample : public godot::GodotScript<godot::Reference> {
	GODOT_CLASS(Sample)

	godot::String data;
public:

	static void _register_methods();

	void _init();

	godot::String get_data() const;
};

#endif