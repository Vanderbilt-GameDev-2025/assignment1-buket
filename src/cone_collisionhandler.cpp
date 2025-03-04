#include "cone_collisionhandler.h"

// #include <godot_cpp/classes/physics_direct_body_state2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void ConeCollisionHandler::_bind_methods() {
    ClassDB::bind_method(D_METHOD("apply_crack_effect"), &ConeCollisionHandler::apply_crack_effect);
}

ConeCollisionHandler::ConeCollisionHandler() {
    set_contact_monitor(true);
    set_max_contacts_reported(10);
}

ConeCollisionHandler::~ConeCollisionHandler() {}

void ConeCollisionHandler::_ready() {
    // set_lock_rotation_enabled(true);
    // set_freeze_enabled(true);
    set_mass(100000.0f);
    // Turn off gravity by setting the gravity scale to zero
    set_gravity_scale(0.0f);
}


void ConeCollisionHandler::_integrate_forces(PhysicsDirectBodyState2D *state) {
    UtilityFunctions::print("_integrate_forces() IS RUNNING!");
    float dt = state->get_step();
    if (dent_cooldown_timer > 0.0f) {
        dent_cooldown_timer -= dt;
    }

    int contact_count = state->get_contact_count();
    if (contact_count == 0) return;

    Vector2 my_velocity = state->get_linear_velocity();

    for (int i = 0; i < 1; i++) {
        Object *collider_obj = state->get_contact_collider_object(i);
        Node *collider_x = Object::cast_to<Node>(collider_obj);
        if (collider_x) {
            UtilityFunctions::print("Collider Object: " + collider_x->get_name());
        }
        if (!collider_obj) continue;

        RigidBody2D *collider_node = Object::cast_to<RigidBody2D>(collider_obj);
        if (!collider_node) continue;

        if (String(collider_node->get_name()) != "Player") {
            continue;
        }

        Vector2 collider_velocity = state->get_contact_collider_velocity_at_position(i);
        Vector2 relative_velocity = my_velocity - collider_velocity;
        float impact_speed = relative_velocity.length();
        UtilityFunctions::print("Impact speed: " + String::num_real(impact_speed));

        if (impact_speed >= impact_threshold && dent_cooldown_timer <= 0.0f) {
            UtilityFunctions::print("Cone hit! Crack level: " + String::num_int64(collision_count));
            apply_crack_effect();
            dent_cooldown_timer = DENT_COOLDOWN_DURATION;
            return;
        }
    }
}


void ConeCollisionHandler::apply_crack_effect() {
    collision_count++;

    Sprite2D *sprite = get_node<Sprite2D>("../Sprite2D");
    UtilityFunctions::print("Sprite Name: " + sprite->get_name());
    if (!sprite) {
        UtilityFunctions::print("Error: Sprite2D not found on cone!");
        return;
    }

    String texture_path;
    if (collision_count == 1) {
        texture_path = "res://graphics/cracked_cones1.png";
    } else if (collision_count == 2) {
        texture_path = "res://graphics/cracked_cones2.png";
    } else if (collision_count >= MAX_COLLISIONS) {
        texture_path = "res://graphics/cracked_cones1.png"; // UPDATE
        UtilityFunctions::print("Cone is fully cracked");
    }

    Ref<Texture2D> new_texture = ResourceLoader::get_singleton()->load(texture_path);
    if (new_texture.is_valid()) {
        sprite->set_texture(new_texture);
    } else {
        UtilityFunctions::print("Failed to load cracked cone texture!");
    }
}

