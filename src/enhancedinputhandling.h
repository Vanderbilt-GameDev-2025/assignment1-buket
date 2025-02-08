#ifndef ENHANCEDINPUTHANDLING_H
#define ENHANCEDINPUTHANDLING_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input_event_key.hpp>

namespace godot {
    class EnhancedInputHandling : public Node2D {
        GDCLASS(EnhancedInputHandling, Node2D)

    private:
        CharacterBody2D *player;
        double originalSpeed;
        double newSpeed;
        int movement_count;
        bool shift_pressed;
        bool is_paused;

    protected:
        static void _bind_methods();

    public:
        EnhancedInputHandling();
        ~EnhancedInputHandling();

        void _ready() override;
        void _input(const Ref<InputEvent> &event) override;

        void pause_game();
        void resume_game();
\
        double get_newSpeed() const;
        void set_newSpeed(const double p_speed);
    };
}

#endif
