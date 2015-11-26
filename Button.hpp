#ifndef BUTTON_H
#define BUTTON_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_rect.h"

enum BtnState {
    None,
    Hover,
    Down,
    Inactive,
}


class Button : Drawable
{
    public:
        Button();
        virtual ~Button();
        void Interactable(bool);
        bool IsInteractable() {return interactable; };

        void Update();



        //override void Draw();
    protected:
    private:

        //void ChangeState(int);

        //std::string image;
        bool interactable = true;

        BtnState state;


};



#endif // BUTTON_H
