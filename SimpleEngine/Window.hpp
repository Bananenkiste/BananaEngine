#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"


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
