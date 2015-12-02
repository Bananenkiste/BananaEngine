#include "Window.hpp"

Window::Window()
{
    window = SDL_CreateWindow(
        "A cool Game",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        std::cout<<"Could not create window: %s\n"<< SDL_GetError()<<std::endl;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
}
