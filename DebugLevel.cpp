#include "DebugLevel.h"
#include "Floor.h"
#include "Player.h"
#include "Upgrade.h"
#include "Enemy.h"
#include "Spawner.h"

Scene* DebugLevel::scene = nullptr;


void DebugLevel::Init()
{

	// Criar cena de jogo
	scene = new Scene();

	background = new Background();
	scene->Add(background, STATIC);
	
	//Cria o jogador na cena
	Player * player = new Player();
	scene->Add(player, MOVING);


	// Adicionar Wall na cena
	Floor* floor;
	float offSetX = 16.0f;
	float offSetY = 16.0f;

	/*
	for (int i = 1; i <= 80; i += 2)
	{
		floor = new Floor();
		floor->MoveTo(offSetX * i, window->Height() - offSetY);
		scene->Add(floor, STATIC);
	}
	*/

	//spawner de inimigos
	Spawner* spw = new Spawner();
	scene->Add(spw, STATIC);

	
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
}