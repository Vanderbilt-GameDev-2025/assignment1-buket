extends RigidBody2D


@export var move_force: float = 100.0

var _up_action := "ui_up"
var _down_action := "ui_down"
var _left_action := "ui_left"
var _right_action := "ui_right"

func _ready() -> void:
	print("Icon RigidBody Initialized at: ", position)
	#set_contact_monitor(true)  # Enable Contact Monitoring
	#set_max_contacts_reported(5)


func _physics_process(delta: float) -> void:
	var direction := Vector2.ZERO
	
	if Input.is_action_pressed(_up_action):
		direction.y -= 1
	if Input.is_action_pressed(_down_action):
		direction.y += 1
	if Input.is_action_pressed(_left_action):
		direction.x -= 1
	if Input.is_action_pressed(_right_action):
		direction.x += 1

	# Normalize to prevent faster diagonal movement
	if direction != Vector2.ZERO:
		direction = direction.normalized()
		apply_central_force(direction * move_force)
