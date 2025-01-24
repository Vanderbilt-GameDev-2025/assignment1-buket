#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/core/class_db.hpp>

namespace godot {
    class AudioManager : public Node {
        GDCLASS(AudioManager, Node)

    private:
        AudioStreamPlayer *applause_player;

    protected:
        static void _bind_methods();

    public:
        AudioManager();
        ~AudioManager();

        void _ready() override;
        void play_applause();
    };
}

#endif
