#ifndef BUTTON_H
#define BUTTON_H

#include "Drawable.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2D.hpp"
#include <iostream>
#include "Settings.hpp"

enum class BtnState {
    None = 0,
    Hover = 1,
    Down = 2,
    Inactive = 3,
};

class Button : public Drawable
{
    private:

        void ChangeState(BtnState);
        void (*ActionCallback)();
        bool interactable;

        BtnState state;
		SDL_Surface *btnImage;
		SDL_Rect* btnSize;
		SDL_Rect* btnPos;
		Vector2D size = Vector2D(0,0);

    public:
        Button();
		Button(int, int, int, int);
        Button(SDL_Rect*,void (*func)());
		Button(ButtonData*);
		
		virtual ~Button();
        void Interactable(bool);
        bool IsInteractable();

        void Update();

        void Action();

        void Draw(SDL_Surface* screen);
};



#endif // BUTTON_H
