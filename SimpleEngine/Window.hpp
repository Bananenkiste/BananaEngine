#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_gamecontroller.h"
#include "SDL2/SDL_mouse.h"
#include "SDL2/SDL_keyboard.h"


class Window
{
    public:
        Window();
        virtual ~Window();
    protected:
    private:
        SDL_Window *window;
};

#endif // WINDOW_H
