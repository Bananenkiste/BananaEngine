#include "Button.hpp"
#include "Loader.hpp"
Button::Button()
{
	btnImage = Loader::LoadImage("Button.bmp");
}

Button::~Button()
{
    //dtor
}

Button::Button(void (*callback)())
{
	btnImage = Loader::LoadImage("Button.bmp");
    //ActionCallback = callback;
}

bool Button::IsInteractable()
{
    return interactable;
}

void Button::Interactable(bool active)
{
    if(interactable != active)
    {
        if(active)
        {
            ChangeState(BtnState::None);
        }
        else
        {
            ChangeState(BtnState::Inactive);
        }
    }
}

void Button::Update()
{
    if(interactable)
    {

    }
}

void Button::Action()
{
    if(interactable && ActionCallback != NULL)
    {
        ActionCallback();
    }
}

void Button::ChangeState(BtnState newState)
{
    if(Button::state == newState)
    {return;}

    /*x= (size*state)%2
    y= (size*state%2)/2*/


}

void Button::Draw(SDL_Surface* screen)
{
	SDL_BlitSurface(btnImage, NULL, screen, NULL);
}



