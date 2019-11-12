#include "sound.h"

Sound::Sound()
{

    this->turn = 1;
}
void Sound::Soundswitch(short int *turn){
    this->turn = *turn;
}
void Sound::next(){
    this->buffer.loadFromFile("sounds/next.wav");
    this->sound.setBuffer(buffer);
    if(this->turn == 1) sound.play();
}
void Sound::back(){
    this->buffer.loadFromFile("sounds/back.wav");
    this->sound.setBuffer(buffer);
    if(this->turn == 1) sound.play();
}
void Sound::play(){
    this->buffer.loadFromFile("sounds/play.wav");
    this->sound.setBuffer(buffer);
    this->sound.setVolume(100);
    if(this->turn == 1) sound.play();
}
void Sound::exit(){
    this->buffer.loadFromFile("sounds/exit.wav");
    this->sound.setBuffer(buffer);
    this->sound.setVolume(100);
    if(this->turn == 1) sound.play();
}
void Sound::check(){
    this->buffer.loadFromFile("sounds/btn121.wav");
    this->sound.setBuffer(buffer);
    this->sound.setVolume(100);
    if(this->turn == 1) sound.play();
}
void Sound::chess(){
    this->buffer.loadFromFile("sounds/chess.wav");
    this->sound.setBuffer(buffer);
    this->sound.setVolume(200);
    if(this->turn == 1) sound.play();
}
void Sound::winning(){
    this->buffer.loadFromFile("sounds/winning.wav");
    this->sound.setBuffer(buffer);
    this->sound.setVolume(200);
    if(this->turn == 1) sound.play();
}
