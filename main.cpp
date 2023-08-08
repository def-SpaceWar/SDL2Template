#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

#include "Window.hpp"

void gameLoop()
{
    Window window("SDL2 Template", 1024, 720);
    SDL_Event event;

    SDL_Texture *blockTexture = window.loadTexture("./res/block.png");
    int r = 0;
    int g = 0;
    int b = 0;

    bool gameRunning = true;
    while (gameRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();
        window.render(blockTexture);
        window.display();

        if (r < 255 && g < 255 && b < 255)
            r++;

        if (r == 255 && g < 255 && b < 255)
            g++;

        if (r == 255 && g == 255 && b < 255)
            b++;

        if (r > 0 && g == 255 && b == 255)
            r--;

        if (r == 0 && g > 0 && b == 255)
            g--;

        if (r == 0 && g == 0 && b > 0)
            b--;

        SDL_SetTextureColorMod(blockTexture, r, g, b);
    }
}

int main()
{
    std::cout << "Hello SDL!!" << std::endl;
    gameLoop();
}
