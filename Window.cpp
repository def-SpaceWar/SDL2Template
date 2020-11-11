#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#include "Window.hpp"

Window::Window(const char *p_title, int p_w, int p_h)
{
    w = p_w;
    h = p_h;
    window = NULL;
    renderer = NULL;

    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture *Window::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, p_filePath);

    return texture;
}

void Window::clear()
{
    SDL_RenderClear(renderer);
}

void Window::render(SDL_Texture * p_texture)
{
    SDL_RenderCopy(renderer, p_texture, NULL, NULL);
}

void Window::render(SDL_Texture * p_texture, SDL_Rect p_source, SDL_Rect p_destination)
{
    SDL_RenderCopy(renderer, p_texture, &p_source, &p_destination);
}

void Window::display()
{
    SDL_RenderPresent(renderer);
}

SDL_Window *Window::getWindow()
{
    return window;
}

SDL_Renderer *Window::getRenderer()
{
    return renderer;
}

int Window::getWidth()
{
    return w;
}

int Window::getHeight()
{
    return h;
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
