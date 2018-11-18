extends "res://test/test.gd"

const simulator = preload("res://bin/Simulator.gdns")

func before_each():
	pass
	
func after_each():
	pass

func before_all():
	pass

func after_all():
	pass

func test_simulator_propogator():
	var instance = simulator.new()
	instance.setSize(3)
	instance.setPsi0([Vector2(5,.1),Vector2(6,2),Vector2(1.2,.1)])
	instance.setHamiltonian([Vector2(5,.1),Vector2(6,2),Vector2(1.2,.1),
							Vector2(3,.1),Vector2(2,.1),Vector2(.2,.4),
							Vector2(4,.2),Vector2(.5,.1),Vector2(3,.1)])
	gut.p("set psi0:" + String(instance.getPsi0()),0)
	gut.p("set hamiltonian:" +  String(instance.getHamiltonian()),0)
	var size1 = instance.getCurrentStateSize()
	instance.step(.01)
	gut.p("run step .01")
	gut.p("propigator:" +  String(instance.getPropagator()),0)
	
