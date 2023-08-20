#include "Spawner.h"
#include "Enemy.h"
#include "Upgrade.h"
#include "DebugLevel.h"
#include <random>

#define timeRate 2

//gerador de números aleatóris. Usado para delimitação de intervalo entre os spawns e a escolha do próximo objeto a ser instanciado
std::random_device rd;
std::mt19937 mt(rd());

Spawner::Spawner() : timer()
{
	timerF = 1.0f;
	timer.Start();
	spawnRate = 1 + mt() % timeRate;
}

Spawner::~Spawner()
{
}

void Spawner::Update()
{

	if (timer.Elapsed(spawnRate))
	{
		timer.Reset();

		spawnRate = 1 + mt() % timeRate ;

		uint spawn = mt() % 100;

		if(spawn < 33)
			DebugLevel::scene->Add(new Enemy(FLYING), MOVING);
		else if (spawn > 32 && spawn < 67)
			DebugLevel::scene->Add(new Enemy(WALKER), MOVING);
		else if(spawn > 66)
			DebugLevel::scene->Add(new Enemy(JUMPER), MOVING);
	}
}

void Spawner::Draw() {}