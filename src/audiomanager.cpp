#include "audiomanager.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/audio_stream.hpp>


using namespace godot;

void AudioManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("play_applause"), &AudioManager::play_applause);
}

AudioManager::AudioManager() {
    applause_player = nullptr;
}

AudioManager::~AudioManager() {}

void AudioManager::_ready() {
    applause_player = memnew(AudioStreamPlayer);

    // Load the applause audio file
    Ref<AudioStream> applause_stream = ResourceLoader::get_singleton()->load("res://audio/applause.mp3");

    if (applause_stream.is_valid()) {
        applause_player->set_stream(applause_stream);
    }
    add_child(applause_player);
}

void AudioManager::play_applause() {
    if (applause_player) {
        applause_player->play();
    }
}
