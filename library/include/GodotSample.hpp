#include <core/Godot.hpp>
#include <Reference.hpp>

using namespace godot;

#ifndef _GODOT_SAMPLE
#define _GODOT_SAMPLE


class SampleClass: public GodotScript<Reference> {
	GODOT_CLASS(SampleClass);
public:
	void test_void_method() {
		Godot::print("This is test");
	}

	Variant method(Variant arg) {
		Variant ret;
		ret = arg;

		return ret;
	}

	static void _register_methods() {
		register_method("method", &SampleClass::method);
		register_method("print", &SampleClass::test_void_method);

		/**
         * How to register exports like gdscript
         * export var _name = "SimpleClass"
         **/
		register_property((char *) "base/name", &SampleClass::_name, String("SimpleClass"));

		/** For registering signal **/
		// register_signal<SimpleClass>("signal_name");
		// register_signal<SimpleClass>("signal_name", "string_argument", GODOT_VARIANT_TYPE_STRING)
	}

    SampleClass() {}

	String _name;
}

#endif
