extends CharacterBody2D

@export var speed := 500
var lives := 3
var score := 0
var balls_to_win := 10

var lives_label: Label
var scores_label: Label
var game_over_label: Label

var enhanced_input_handling: EnhancedInputHandling

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	process_mode = Node.PROCESS_MODE_ALWAYS
	position = Vector2(646, 216)
	
	# Get references to the Labels in the scene
	lives_label = get_parent().get_node("LivesLabel")
	scores_label = get_parent().get_node("ScoresLabel")
	game_over_label = get_parent().get_node("GameOverLabel")
	
	_update_lives_label()
	_update_scores_label()
	
	enhanced_input_handling = EnhancedInputHandling.new()
	add_child(enhanced_input_handling)
	enhanced_input_handling.set_newSpeed(1000)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	if get_tree().paused or lives <= 0:  # Prevent movement when the game is paused
		return
	var direction = Input.get_vector("left", "right", "up", "down")
	velocity = direction * speed
	move_and_slide()
	

func _update_lives_label() -> void:
	if lives_label:
		lives_label.text = "Lives: " + str(lives)


func _update_scores_label() -> void:
	if scores_label:
		scores_label.text = "Score: " + str(score)


func reduce_lives() -> void:
	lives -= 1
	_update_lives_label()
	if lives <= 0:
		_game_over()

func increase_score(points: int) -> void:
	score += points
	_update_scores_label()
	
	if score == 3:
		show_hat_trick_message()
		play_applause_sound()
		
	if score == 5:
		show_king_scorer_message()
		play_applause_sound()
	
	if score >= balls_to_win:
		_game_won()


func show_hat_trick_message() -> void:
	var hat_trick_label = $"../HatTrickLabel"
	hat_trick_label.visible = true
	await get_tree().create_timer(6).timeout
	hat_trick_label.visible = false
	

func show_king_scorer_message() -> void:
	var king_scorer_label = $"../KingScorerLabel"
	king_scorer_label.visible = true
	await get_tree().create_timer(6).timeout
	king_scorer_label.visible = false


func _game_over() -> void:
	if game_over_label:
		game_over_label.text = "Game Over."
		game_over_label.visible = true
	get_tree().paused = true


func _game_won() -> void:
	if game_over_label:
		game_over_label.text = "You are the CHAMPION!"
		game_over_label.visible = true
	get_tree().paused = true
	
	
func play_applause_sound():
	var audio_manager = $"../AudioManager"
	if audio_manager:
		audio_manager.call("play_applause")
