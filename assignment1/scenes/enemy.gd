extends Area2D

var speed: int
var direction: Vector2

var screen_size: Vector2
var rng := RandomNumberGenerator.new()

func _ready() -> void:
	screen_size = get_viewport_rect().size
	position = Vector2(rng.randi_range(100, screen_size.x - 100), rng.randi_range(100, screen_size.y - 100))
	speed = rng.randi_range(200, 400)
	direction = Vector2(rng.randf_range(-1, 1), rng.randf_range(-1, 1)).normalized()

	
func _process(delta: float) -> void:
	position += direction * speed * delta

	# Reverse direction if hitting the screen bounds
	if position.x <= 0 or position.x >= screen_size.x:
		direction.x = -direction.x + rng.randf_range(-0.2, 0.2)
	if position.y <= 0 or position.y >= screen_size.y:
		direction.y = -direction.y + rng.randf_range(-0.2, 0.2)


func _on_body_entered(body: Node2D) -> void:
	if body.is_in_group("Player"):
		body.reduce_lives()
	
