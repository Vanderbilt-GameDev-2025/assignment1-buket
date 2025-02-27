# Mourinhoball!

## Game Description
Welcome to Mourinhoball, a 2D platformer where you play as soccer player Youssef En-Nesyri, navigating platforms with up, down, right, left keys to collect 10 balls while avoiding hazards such as spiky cones and an animated manager Mourinho! The game challenges players to collect all the balls and claim the championship trophy while managing lives and dodging enemies.

## Core Mechanics:
- Player Movement: Navigate the player using arrow keys to jump and move across platforms.
- Scoring: Collect balls to increase your score. Reach 10 goals to win the game.
- Lives System: Start the game with 3 lives. Losing all lives results in "Game Over."
- Dynamic Hazards: Avoid Mourinho and spikes, as they reduce lives on contact.
- Extra Feedback:
  - At 3 goals: "Hat Trick!" message appears, accompanied by applause sound.
  - At 5 goals: "King Scorer!" message appears, again with applause sound.

## Screenshots
- Main Gameplay View: 
![Gameplay Screenshot 1](readme_screenshots/start.png)

- Scoring System:
![Gameplay Screenshot 2](readme_screenshots/scored_3.png)

- Game Over:
![Gameplay Screenshot 3](readme_screenshots/gameover.png)

## Compilation Steps
1. Clone the repository.
2. Build the GDExtension: 	``` scons platform=macos ```
3. Open in Godot by launching Godot 4.3. and importing the project by selecting the project.godot file in the repository folder.
4. Run the game by pressing the Play button in Godot.

## Game Feautures
### Core Features:
1. Ball Collection:
- Collect 10 balls to win the game.

2. Lives System:
- Start with 3 lives.
- Lose lives when colliding with the enemy or spikes.

3. Hazards:
- Avoid enemiy that moves randomly on the screen.
- Avoid spikes.

### Extra Credit Features:
1. Sound Effects:
- Context-sensitive sound effects (applause when scoring 3 or 5 goals).

## Video Demo
A gameplay demo can be found here: [video link](https://youtu.be/UYNzNhDd5VQ)