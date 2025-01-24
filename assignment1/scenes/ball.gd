extends Area2D

@export var points := 1

func _on_body_entered(body: Node) -> void:
	if body.is_in_group("Player"):
		body.increase_score(points)
		get_parent().queue_free()
