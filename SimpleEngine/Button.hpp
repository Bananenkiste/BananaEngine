#ifndef BUTTON_H
#define BUTTON_H

#include "Drawable.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_rect.h"

enum BtnState {
    None,
    Hover,
    Down,
    Inactive,
};

class Button : public Drawable
{
    private:

        void ChangeState(BtnState);
        void* ActionCallback;
        //std::string image;
        bool interactable;

        BtnState state;

    public:
        Button();
        Button(void* );
        virtual ~Button();
        void Interactable(bool);
        bool IsInteractable();

        void Update();

        void Action();

        void Draw();
};



#endif // BUTTON_H
