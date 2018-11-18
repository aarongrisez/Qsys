extends "res://addons/gut/test.gd"

# class member variables go here, for example:
# var a = 2
# var b = "textvar"

func assert_vec_eq_thresholded(vec1,vec2,epsilon,message):
	assert_eq(abs(vec1.x - vec2.x) < epsilon,true,message)
	assert_eq(abs(vec1.y - vec2.y) < epsilon,true,message)

#func _process(delta):
#	# Called every frame. Delta is time since last frame.
#	# Update game logic here.
#	pass
