extends Timer

#1. load the scene
var ball_scene: PackedScene = load('res://scenes/ball.tscn')

var ball_positions = [
	Vector2(115, 111),
	Vector2(469, 430),
	Vector2(1180, 612),
	Vector2(1040, 268),
	Vector2(118, 612),
	Vector2(294, 252),
	Vector2(900, 100),
	Vector2(781, 376),
	Vector2(1029, 453),
	Vector2(305, 433),
]

var counter = 0

func _ready() -> void:
	show_goal_message()


func _on_timeout() -> void:
	# 2. create an instance
	var ball = ball_scene.instantiate()
	# 3. attach the node to the scene tree
	ball.position = ball_positions[counter]
	counter += 1
	$"../Balls".add_child(ball)


func restart_game() -> void:
	get_tree().paused = false
	get_tree().reload_current_scene()


func _on_restart_button_pressed() -> void:
	restart_game()
	
	
func show_goal_message() -> void:
	var goal_label = $"../GoalLabel"
	goal_label.visible = true
	await get_tree().create_timer(5).timeout
	goal_label.visible = false
