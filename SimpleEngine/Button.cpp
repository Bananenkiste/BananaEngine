#include "Button.hpp"
#include "Loader.hpp"
#include "Input.hpp"

Button::Button()
{
	btnImage = Loader::LoadImage("Button2.bmp");
	btnSize = NewRect(0, 0, 320, 180);
	btnPos = NewRect(20, 20, 120, 60);
	size = Vector2D(320, 180);
}

Button::Button(int x, int y, int w, int h)
{
	btnImage = Loader::LoadImage("Button2.bmp");
	btnSize = NewRect(0, 0, 320, 180);
	btnPos = NewRect(x, y, w, h);
	size = Vector2D(320, 180);
}

Button::Button(SDL_Rect* pos, void(*callback)())
{
	btnPos = pos;
	btnImage = Loader::LoadImage("Button2.bmp");
	size = Vector2D(320, 180);
	ActionCallback = callback;
}


Button::Button(ButtonData* data)
{
	btnSize = NewRect(0, 0, 320, 180);
	btnPos = NewRect(data->pos.x, data->pos.y, data->size.x, data->size.y);
	btnImage = Loader::LoadImage("Button2.bmp");
	size = Vector2D(320, 180);
}



Button::~Button()
{
	SDL_FreeSurface(btnImage);
	delete btnSize;
	delete btnPos;
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
	if (state != BtnState::Inactive)
	{
		Vector2D* mouse = Input::GetMousePos();
		if (mouse->x > btnPos->x && mouse->x < btnPos->x + btnPos->w && mouse->y > btnPos->y && mouse->y < btnPos->y + btnPos->h)
		{
			if (state == BtnState::Down && !(Input::GetKey(SDLK_RETURN) || Input::GetMouseBtn(1)))
			{
				std::cout << "Button click" << std::endl;
			}
			if (Input::GetKey(SDLK_RETURN) || Input::GetMouseBtn(1))
			{
				ChangeState(BtnState::Down);
			}
			else
			{
				ChangeState(BtnState::Hover);
			}
		}
		else
		{
			ChangeState(BtnState::None);
		}
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
    {
		return;
	}
	state = newState;
	int i = (int)state;
	btnSize = NewRect(0, size.y*i, size.x, size.y);
}

void Button::Draw(SDL_Surface* screen)
{
	SDL_BlitScaled(btnImage, btnSize, screen, btnPos);
}



