#pragma once
#include "Vector2D.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include <map>


struct ButtonData
{
	std::string title;
	std::string background;

	std::string function;
	std::string parameter;

	Vector2D pos;
	Vector2D size;

	ButtonData() : pos(0, 0), size(0, 0)
	{	}

	ButtonData(std::string aTitle, std::string aBackground, Vector2D aPos, Vector2D aSize) : title(aTitle), background(aBackground), pos(aPos), size(aSize)
	{	}

	ButtonData(std::string aTitle, std::string aBackground, Vector2D aPos, Vector2D aSize, std::string aFunction, std::string parameters) : title(aTitle), background(aBackground), pos(aPos), size(aSize), function(aFunction), parameter(parameters)
	{	}

};

struct ScreenData
{
	std::string title;
	std::string background;

	std::vector<ButtonData> buttons;

	ScreenData(std::string aTitle, std::string aBackground): title(aTitle), background(aBackground)
	{	}

};



class Settings
{

private:

	static std::map<std::string, ScreenData> screens;



public:

	static void LoadXML(std::string);
	static void CreateScreen(rapidxml::xml_node<>*);
	static ButtonData CreateButton(rapidxml::xml_node<>*);

	static ScreenData* GetSceneData(std::string);

	static std::vector<int> GetRect(std::string const&, char);

};

