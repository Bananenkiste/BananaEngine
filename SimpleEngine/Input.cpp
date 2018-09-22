#include "Input.hpp"
#include <iostream>


Vector2D Input::mousePos = Vector2D(0,0);
std::map<SDL_Keycode, bool> Input::downKeys;
//std::map<Input::Key, SDL_Keycode> Input::keymapping;

std::map<int, bool> Input::mouseBtn;

void Input::Init()
{
	mousePos = Vector2D(0, 0);

}

void Input::Update(SDL_Event* event)
{
	bool keyDown = false;
	switch (event->type)
	{
	case SDL_KEYDOWN: case SDL_KEYUP:
		keyDown = event->type == SDL_KEYDOWN ? true : false;
		KeyDown(event->key.keysym.sym, keyDown);	
		break;
	case SDL_MOUSEMOTION:
		mousePos.Set(event->motion.x, event->motion.y);
		break;
	case SDL_MOUSEBUTTONUP: case SDL_MOUSEBUTTONDOWN:
		keyDown = event->type == SDL_MOUSEBUTTONDOWN ? true : false;
		MouseBtn(event->button.button, keyDown);
		break;
	}
}

void Input::MouseBtn(int btn, bool state)
{
	mouseBtn[btn] = state;
}

void Input::KeyDown(SDL_Keycode key, bool down)
{
	downKeys[key] = down;
}

bool Input::GetKey(SDL_Keycode key)
{
	return downKeys[key];
}

bool Input::GetMouseBtn(int key)
{
	if(mouseBtn.count(key)>0)
		return mouseBtn[key];
	return false;
}

Vector2D* Input::GetMousePos()
{
	return &mousePos;
}

