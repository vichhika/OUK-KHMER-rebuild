#ifndef MUSIC_H     
#define MUSIC_H

#include <SFML/Audio.hpp>

class music
{
private:
    sf::Music soundtrack;
    short int turn;
public:
    music();
    void music_play();
    void music_pause();
};

#endif // MUSIC_H
