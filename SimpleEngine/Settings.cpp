#include "Settings.hpp"
#include <vector>
#include <sstream>
#include <iostream>


std::map<std::string,ScreenData> Settings::screens;

void Settings::LoadXML(std::string file)
{
	rapidxml::file<>source(file.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(source.data());

	rapidxml::xml_node<>* screens = doc.first_node("Screens");
	if (screens != NULL)
	{
		for (rapidxml::xml_node<> *nodes = screens->first_node("Screen"); nodes; nodes = nodes->next_sibling())
		{
			CreateScreen(nodes);
		}
	}
}


void Settings::CreateScreen(rapidxml::xml_node<>* node)
{
	ScreenData data =ScreenData(node->first_attribute("name")->value(), node->first_attribute("background")->value());
	std::cout << "Screen: " << data.title << std::endl;

	for (rapidxml::xml_node<> *btn_node = node->first_node("Button"); btn_node; btn_node = btn_node->next_sibling())
	{
		std::cout << "Button: " << btn_node->first_attribute("name")->value() << std::endl;
		data.buttons.push_back(CreateButton(btn_node));
	}

	screens.insert(screens.end(), std::pair<std::string, ScreenData>(data.title, data));
}

ButtonData Settings::CreateButton(rapidxml::xml_node<>* btnNode)
{
	ButtonData btn = ButtonData();
	std::string value;
	
	for (rapidxml::xml_attribute<> * btnAtt = btnNode->first_attribute(); btnAtt; btnAtt = btnAtt->next_attribute())
	{
		value = btnAtt->name();
		if (value.compare("name") == 0)
		{
			btn.title = btnAtt->value();
			continue;
		}
		if (value.compare("background") == 0)
		{
			btn.background = btnAtt->value();
			continue;
		}
		if (value.compare("rect") == 0)
		{
			std::vector<int> values = Settings::GetRect(btnAtt->value(), ',');
			if (values.size() == 4)
			{
				btn.pos = Vector2D(values[0], values[1]);
				btn.size = Vector2D(values[2], values[3]);
			}
			continue;
		}
		if (value.compare("function") == 0)
		{
			btn.function = btnAtt->value();
			continue;
		}
	}
	return btn;
}




ScreenData* Settings::GetSceneData(std::string value)
{
	std::map<std::string, ScreenData>::iterator it = screens.find(value);
	if (it != screens.end())
	{
		return &it->second;
	}
	return NULL;
}


std::vector<int> Settings::GetRect(std::string const & s, char delim)
{
	std::vector<int> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		result.push_back(std::stoi(std::move(token)));
	}

	return result;
}