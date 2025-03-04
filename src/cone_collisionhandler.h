#ifndef CONE_COLLISIONHANDLER_H
#define CONE_COLLISIONHANDLER_H

#include <godot_cpp/classes/rigid_body2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/physics_direct_body_state2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {

class ConeCollisionHandler : public RigidBody2D {
    GDCLASS(ConeCollisionHandler, RigidBody2D)

private:
    int collision_count = 0;
    float dent_cooldown_timer = 0.0f;  // Cooldown for impact processing
    float impact_threshold = 200.0f;   // Minimum speed for an impact to register
    static constexpr float DENT_COOLDOWN_DURATION = 1.0f; // Cooldown time
    static constexpr int MAX_COLLISIONS = 3; 

protected:
    static void _bind_methods();

public:
    ConeCollisionHandler();
    ~ConeCollisionHandler();

    void _ready() override;
    void _integrate_forces(PhysicsDirectBodyState2D *state) override;
    void apply_crack_effect();
};

} // namespace godot

#endif // CONE_COLLISIONHANDLER_H
