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

func test_simulator_propogator():
	var instance = simulator.new()
	instance.setSize(3)
	instance.setPsi0([Vector2(0,0),Vector2(0,0),Vector2(1,0)])
	instance.setHamiltonian([Vector2(0.4147272586872562,0),Vector2(0.2849716083377269,0.01667585975115329),Vector2(0.5792858065923596,0.04493069203570912),
							 Vector2(0.2849716083377269,-0.01667585975115329),Vector2(0.17632777798815139,0),Vector2(0.44357036381369286,0.03592326101885296),
							 Vector2(0.5792858065923596,-0.04493069203570912),Vector2(0.44357036381369286,-0.03592326101885296),Vector2(0.7027700178027618,0)])
	for i in range(5001):
		instance.step(.01)
	print(instance.getCurrentState())
	print(instance.getProbabilityDensity())
	print(instance.measure())
	#print(instance.getErrorMessage())
