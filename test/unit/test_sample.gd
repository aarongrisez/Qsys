extends "res://addons/gut/test.gd"

const Simple = preload("res://bin/QSys.gdns")

onready var simple_instance = Simple.new()

func before_each():
	pass
	
func after_each():
	pass

func before_all():
	pass

func after_all():
	pass

func test_sample():
		assert_eq(simple_instance.get_data(),'Hello World from C++')
	
	
