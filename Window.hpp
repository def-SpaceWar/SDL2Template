#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>

class Window {
public:
    Window(const char *p_title, int p_w, int p_h);
    SDL_Texture *loadTexture(const char *p_filePath);
    void clear();
    void render(SDL_Texture *p_texture);
    void render(SDL_Texture *p_texture, SDL_Rect p_source, SDL_Rect p_destination);
    void display();

    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    int getWidth();
    int getHeight();

    ~Window();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int w;
    int h;
};
