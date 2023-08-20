
#include "Level.h"

Scene* Level::scene = nullptr;

void Level::Init()
{
	scene = new Scene();

	background = new Background();
	scene->Add(background, STATIC);

	player = new Player();
	scene->Add(player, MOVING);

	Floor* floor;
	float offSetX = 16.0f;
	float offSetY = 16.0f;

	for (int i = 1; i <= 46; i += 2)
	{
		floor = new Floor();
		floor->MoveTo(offSetX * i, window->Height() - offSetY);
		scene->Add(floor, STATIC);
	}
}

void Level::Finalize()
{
	delete scene;
}

void Level::Update()
{
	scene->Update();
	scene->CollisionDetection();
}

void Level::Draw()
{
	scene->Draw();
}