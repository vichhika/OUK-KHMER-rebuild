#include "music.h"

music::music()
{
    this->soundtrack.openFromFile("music/flute.ogg");
}
void music::music_play(){
    this->soundtrack.play();
    this->soundtrack.setLoop(true);
    this->soundtrack.setVolume(50);
    //this->soundtrack.play();
}
void music::music_pause(){
    //this->soundtrack.pause();
    this->soundtrack.setVolume(0);
}
