#pragma once
#include "Vector2D.hpp"
#include "SDL.h"
#include <vector>
#include <map>

class Input
{
public:

	enum Key
	{
		Up,
		Down,
		Left,
		Right,
	};

	enum Mouse
	{
		LeftMouse,
		RightMouse,
	};

	static void Init();
	static void Update(SDL_Event* keyEvent);

	static bool GetKey(SDL_Keycode);
	static bool GetMouseBtn(int);
	static Vector2D* GetMousePos();

private:
	static Vector2D mousePos;

	static void KeyDown(SDL_Keycode, bool);
	static void MouseBtn(int, bool);
	
	
	
	static std::map<Key, SDL_Keycode> keymapping;
	static std::map<SDL_Keycode, bool> downKeys;
	static std::map<int, bool> mouseBtn;


};

