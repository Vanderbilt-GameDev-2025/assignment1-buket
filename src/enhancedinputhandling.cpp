#include "enhancedinputhandling.h"
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

using namespace godot;

void EnhancedInputHandling::_bind_methods() {
    // Bind the methods
    ClassDB::bind_method(D_METHOD("get_newSpeed"), &EnhancedInputHandling::get_newSpeed);
    ClassDB::bind_method(D_METHOD("set_newSpeed", "p_speed"), &EnhancedInputHandling::set_newSpeed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "newSpeed"), "set_newSpeed", "get_newSpeed");
}

EnhancedInputHandling::EnhancedInputHandling() {
    player = nullptr;
    newSpeed = 1000.0;
    is_paused = false;
}

EnhancedInputHandling::~EnhancedInputHandling() {}

double EnhancedInputHandling::get_newSpeed() const {
    return newSpeed;
}

void EnhancedInputHandling::set_newSpeed(const double p_speed) {
    newSpeed = p_speed;
}

void EnhancedInputHandling::_ready() {
    set_process_input(true);
    set_process(true);
    Node* parent_node = get_parent();
    
    if (!parent_node) return;
    
    player = Object::cast_to<CharacterBody2D>(parent_node);
    if (!player) return;

    originalSpeed = player->get("speed");
    shift_pressed = false;
    movement_count = 0;
}

void EnhancedInputHandling::_input(const Ref<InputEvent>& event) {

    if (player && player->get("lives").operator int() <= 0) {
        return;
    }


    Ref<InputEventKey> key_event = event;

    if (key_event.is_valid() && !key_event->is_echo()) {
        bool pressed = key_event->is_pressed();
        int key_code = key_event->get_keycode();

        // Check for Shift key press
        if (key_code == Key::KEY_SHIFT) {
            shift_pressed = pressed;
        }

        // Movement keys (WASD or Arrow Keys)
        if (key_code == Key::KEY_UP || key_code == Key::KEY_DOWN ||
            key_code == Key::KEY_LEFT || key_code == Key::KEY_RIGHT ||
            key_code == Key::KEY_W || key_code == Key::KEY_S ||
            key_code == Key::KEY_A || key_code == Key::KEY_D) {

            if (pressed) {
                movement_count += 1;
            } else {
                movement_count -= 1;
                if (movement_count < 0) movement_count = 0;
            }
        }

        if (shift_pressed && movement_count > 0) {
            player->set("speed", newSpeed);  // Sprinting speed
        } else {
            player->set("speed", originalSpeed);  // Normal speed
        }

        // Pause/Resume Logic (Shift + P)
        if (key_code == Key::KEY_P && shift_pressed) {
            if (pressed) {
                if (is_paused) {
                    UtilityFunctions::print("Resuming game...");
                    resume_game();
                } else {
                    UtilityFunctions::print("Pausing game...");
                    pause_game();
                }
            }
        }
    }
}


void EnhancedInputHandling::pause_game() {
    is_paused = true;
    get_tree()->set_pause(true);
    UtilityFunctions::print("Game Paused");
}

void EnhancedInputHandling::resume_game() {
    is_paused = false;
    get_tree()->set_pause(false);
    UtilityFunctions::print("Game Resumed");
}