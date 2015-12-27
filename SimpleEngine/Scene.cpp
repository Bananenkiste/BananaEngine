#include "Scene.hpp"



Scene::Scene()
{
	btn = new Button();
}


Scene::~Scene()
{
	delete btn;
}

void Scene::Update()
{
	btn->Update();
}

void Scene::Draw(SDL_Surface* screen)
{
	btn->Draw(screen);
}
