#ifndef WINDOW_H
#define WINDOW_H

<<<<<<< HEAD
#include "SDL.h"
#include <iostream>
=======
#include "SDL2/SDL.h"
#include "SDL2/SDL_gamecontroller.h"
#include "SDL2/SDL_mouse.h"
#include "SDL2/SDL_keyboard.h"

>>>>>>> c973420843808dd1d6cc7d6762ffb60a9e13699a

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
