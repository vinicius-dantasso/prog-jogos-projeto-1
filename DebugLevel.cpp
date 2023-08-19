

#include "Engine.h"
#include "DebugLevel.h"
#include "Player.h"
#include "Floor.h"

void DebugLevel::Init()
{
	scene = new Scene();

	// Adicionar Player na cena
	Player* player = new Player();
	scene->Add(player, MOVING);

	// Adicionar Wall na cena
	Floor* floor;
	float offSetX = 16.0f;
	float offSetY = 16.0f;

	for (int i = 1; i <= 80; i += 2)
	{
		floor = new Floor();
		floor->MoveTo(offSetX * i, window->Height() - offSetY);
		scene->Add(floor, STATIC);
	}

}

void DebugLevel::Finalize()
{
	delete scene;
}

void DebugLevel::Update()
{
	if (window->KeyPress('B'))
		viewBBox != viewBBox;

	scene->Update();
	scene->CollisionDetection();
}

void DebugLevel::Draw()
{
	scene->Draw();

	if (viewBBox)
		scene->DrawBBox();
}