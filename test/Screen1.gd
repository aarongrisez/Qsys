extends Control

const simulator = preload("res://bin/Simulator.gdns")

# class member variables go here, for example:
var instance = simulator.new()

func _ready():
	# Called when the node is added to the scene for the first time.
	# Initialization here
	instance.setSize(3)
	instance.setPsi0([Vector2(0,0),Vector2(0,0),Vector2(1,0)])
	instance.setHamiltonian([Vector2(0.4147272586872562,0),Vector2(0.2849716083377269,0.01667585975115329),Vector2(0.5792858065923596,0.04493069203570912),
							 Vector2(0.2849716083377269,-0.01667585975115329),Vector2(0.17632777798815139,0),Vector2(0.44357036381369286,0.03592326101885296),
							 Vector2(0.5792858065923596,-0.04493069203570912),Vector2(0.44357036381369286,-0.03592326101885296),Vector2(0.7027700178027618,0)])
	pass

func _process(delta):
#	# Called every frame. Delta is time since last frame.
	instance.step(delta)

func _on_Button_pressed():
	var lab = get_node("Menu/Button/Label")
	lab.text = str(instance.measure())
