#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

int main(int argc, char *argv[])
{
//    Graphics graphics;
//    graphics.init();
//
//    SDL_Texture* background = graphics.loadTexture("img\\back.png");
//    SDL_Texture* gamelose = graphics.loadTexture("img\\gamelose.png");
//    SDL_Texture* start = graphics.loadTexture("img\\start.png");
//    SDL_Texture* exit = graphics.loadTexture("img\\exit.png");
//    SDL_Texture* playagain = graphics.loadTexture("img\\playagain.png");
//
//    Mix_Chunk *soundeat = graphics.loadSound("sound\\sound_eat.mp3");
//    Mix_Chunk *soundlose = graphics.loadSound("sound\\sound_lose.mp3");
//    Mix_Chunk *soundclick = graphics.loadSound("sound\\sound_click.mp3");
     try
  {
    Snake s;
    return s.exec();
  } catch (exception &e)
  {
    cerr << e.what() << endl;
    return 1;
  }
    return 0;
}
