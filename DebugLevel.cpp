
#include "Engine.h"
#include "DebugLevel.h"
#include "Floor.h"
#include "Upgrade.h"
#include "Enemy.h"

Scene* DebugLevel::scene = nullptr;

void DebugLevel::Init()
{
	// Criar cena de jogo
	scene = new Scene();

	// Adicionar Player na cena
	player = new Player();
	scene->Add(player, MOVING);

	// Adiciona uma fonte
	font = new Font("Resources/verdana12.png");
	font->Spacing("Resources/verdana12.dat");

	// Adicionar Wall na cena
	Floor* floor;
	float offSetX = 16.0f;
	float offSetY = 16.0f;

	for (int i = 1; i <= 46; i += 2)
	{
		floor = new Floor();
		floor->MoveTo(offSetX * i, window->Height() - offSetY);
		scene->Add(floor, STATIC);
	}

	// Adicionar Upgrade na cena
	Upgrade* upgrade = new Upgrade();
	scene->Add(upgrade, MOVING);

	// Adicionar Inimigo Voador
	Enemy* enemy;
	enemy = new Enemy(FLYING);
	scene->Add(enemy, MOVING);

	enemy = new Enemy(WALKER);
	scene->Add(enemy, MOVING);

	enemy = new Enemy(JUMPER);
	scene->Add(enemy, MOVING);

}

void DebugLevel::Finalize()
{
	delete scene;
}

void DebugLevel::Update()
{
	scene->Update();
	scene->CollisionDetection();
}

void DebugLevel::Draw()
{
	scene->Draw();
	//scene->DrawBBox();
}