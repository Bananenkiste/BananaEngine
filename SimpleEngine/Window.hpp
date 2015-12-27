#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "SDL.h"
#include "SDL_gamecontroller.h"
#include "SDL_mouse.h"
#include "SDL_keyboard.h"
#include "Scene.hpp"

class Window
{
    public:
        Window();
        virtual ~Window();

		void Update();
		void Draw();
    protected:
    private:

		Scene* scene;
        SDL_Window *window;
		SDL_Surface* screen;
};

#endif // WINDOW_H
