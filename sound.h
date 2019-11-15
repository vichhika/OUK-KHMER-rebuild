#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>

class Sound
{
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
public:
    short int turn;
    Sound();
    void Soundswitch(short int *turn);
    void play();
    void next();
    void back();
    void exit();
    void check();
    void chess();
    void winning();
};

#endif // SOUND_H
