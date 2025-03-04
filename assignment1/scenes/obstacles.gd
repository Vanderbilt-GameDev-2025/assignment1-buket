extends RigidBody2D


func _ready() -> void:
	#add_to_group("RigidBody2D")
	print("Cone Initialized: ", name)
	#set_freeze_enabled(true)
	#set_freeze_mode(RigidBody2D.FREEZE_MODE_STATIC)
	# sleeping = true
	# set_freeze_enabled(false)
	

#func _physics_process(delta: float) -> void:
	#pass
	##set_scale(Vector2(0.6,0.6))
	## print("Cone Processing: ", name, " | Position: ", position, " | Visible: ", visible)


#func _on_body_entered(body: Node2D) -> void:
	#if body.is_in_group("Player"):
		#body.reduce_lives()
		
