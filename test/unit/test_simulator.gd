extends "res://addons/gut/test.gd"

const simulator = preload("res://bin/Simulator.gdns")

func before_each():
	pass
	
func after_each():
	pass

func before_all():
	pass

func after_all():
	pass

func test_simulator_propigator():
	var instance = simulator.new()
	instance.setHamiltonian([Vector2(1,.1),Vector2(1,.1),Vector2(1,.1),
							Vector2(1,.1),Vector2(1,.1),Vector2(1,.1),
							Vector2(1,.1),Vector2(1,.1),Vector2(1,.1)])
	assert_eq(instance.getHamiltonian(),[Vector2(1,.1),Vector2(1,.1),Vector2(1,.1),
							Vector2(1,.1),Vector2(1,.1),Vector2(1,.1),
							Vector2(1,.1),Vector2(1,.1),Vector2(1,.1)])
	
	
	
