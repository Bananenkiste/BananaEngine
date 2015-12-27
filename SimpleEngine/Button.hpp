#ifndef BUTTON_H
#define BUTTON_H

#include "Drawable.hpp"
#include "SDL.h"
#include "SDL_image.h"

enum class BtnState {
    None,
    Hover,
    Down,
    Inactive,
};

class Button : public Drawable
{
    private:

        void ChangeState(BtnState);
        void (*ActionCallback)();
        //std::string image;
        bool interactable;

        BtnState state;
		SDL_Surface *btnImage;

    public:
        Button();
        Button(void (*func)());
        virtual ~Button();
        void Interactable(bool);
        bool IsInteractable();

        void Update();

        void Action();

        void Draw(SDL_Surface* screen);
};



#endif // BUTTON_H
