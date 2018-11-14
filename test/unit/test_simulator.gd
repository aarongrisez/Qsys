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

func assert_eq_thresholded(vec1,vec2,epsilon,message):
	assert_eq(abs(vec1.x - vec2.x) < epsilon,true,message)
	assert_eq(abs(vec1.y - vec2.y) < epsilon,true,message)
	

func test_simulator_propigator():
	var instance = simulator.new()
	instance.setSize(3)
	instance.setHamiltonian([Vector2(5,.1),Vector2(6,2),Vector2(1.2,.1),
							Vector2(3,.1),Vector2(2,.1),Vector2(.2,.4),
							Vector2(4,.2),Vector2(.5,.1),Vector2(3,.1)])
	var result = instance.getHamiltonian()
	assert_eq_thresholded(result[0],Vector2(5,.1),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[1],Vector2(6,2),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[2],Vector2(1.2,.1),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[3],Vector2(3,.1),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[4],Vector2(2,.1),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[5],Vector2(.2,.4),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[6],Vector2(4,.2),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[7],Vector2(.5,.1),.1,"mismatch for hamiltonian")
	assert_eq_thresholded(result[8],Vector2(3,.1),.1,"mismatch for hamiltonian")
	
	
