#include "Button.hpp"

Button::Button()
{
    //ctor
}

Button::~Button(){}
{
    //dtor
}


void Button::Interactable(bool active)
{
    if(interactable != active)
    {
        if(active)
        {
            ChangeState(btnState.None);
        }
        else
        {
            ChangeState(btnState.Inactive)
        }
    }
}

void Button::Update()
{
    if(interactable)
    {

    }
}

/*void Button::ChangeState(int newState)
{
    if(Button::state == newState)
    {return;}

    /*x= (size*state)%2
    y= (size*state%2)/2*/


}*/

/*override void Button::Draw()
{

}*/


