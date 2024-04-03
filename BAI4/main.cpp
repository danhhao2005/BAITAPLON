#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
/*
int madfgdgin(int argc, char *argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    SDL_Texture* background = loadTexture("bikiniBottom.jpg", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    SDL_Texture* spongeBob = loadTexture("Spongebob.png", renderer);
    renderTexture(spongeBob, 200, 200, renderer);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    SDL_DestroyTexture( spongeBob );
    spongeBob = NULL;
    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}*/

int main(int argc, char *argv[])
{
//toa do chuot

    Graphics graphics;
    graphics.init();

    SDL_Event event;
    int x, y;
    while (true) {
        SDL_GetMouseState(&x, &y);
        cerr << x << ", " << y << endl;

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
        }
        SDL_Delay(100);
    }

    graphics.quit();
    return 0;

//hinh chu nhat

Graphics graphics;
    graphics.init();

    SDL_Event event;
    int x, y;
    while (true) {
        SDL_Rect rect;
    rect.x=100;
    rect.y=100;
    rect.h=100;
    rect.w=100;
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 0 );
    SDL_RenderFillRect(graphics.renderer, &rect);
    SDL_RenderPresent(graphics.renderer);

    SDL_Event event;
    int x, y;
 SDL_GetMouseState(&x, &y);
    cerr << ((x > 100 && y > 100 && x < 200 && y < 200) ? "In\n" : "Out\n");

    SDL_PollEvent(&event);

        }
        SDL_Delay(100);
    }


//keo tha chuot

Graphics graphics;
    graphics.init();

    SDL_Event event;
    int x, y;
    while (true) {
        SDL_GetMouseState(&x, &y);
        //cerr << ((x > 100 && y > 100 && x < 200 && y < 200)...

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
            case SDL_MOUSEBUTTONDOWN:
                 cerr << "Down at (" << x << ", " << y << ")\n";
                 break;
            case SDL_MOUSEBUTTONUP:
                 cerr << "Up at (" << x << ", " << y << ")\n";
                 break;
        }
        SDL_Delay(100);
    }

 }

