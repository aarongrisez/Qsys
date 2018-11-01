extends "res://addons/gut/test.gd"

const Simple = preload("res://bin/QSys.gdns")
const Simple2 = preload("res://bin/QSys1.gdns")

onready var simple_instance = Simple.new()
onready var simple_instance_1 = Simple2.new()

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
	
	
