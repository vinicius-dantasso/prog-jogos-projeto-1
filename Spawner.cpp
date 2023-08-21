#include "Spawner.h"
#include "Enemy.h"
#include "Upgrade.h"
#include "DebugLevel.h"
#include "Level.h"
#include <random>

#define timeRate 2

//gerador de números aleatórios. Usado para delimitação de intervalo entre os spawns e a escolha do próximo objeto a ser instanciado
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

		if (Level::dist <= 50 || Level::dist > 50)
		{
			if (spawn < 33)
				Level::scene->Add(new Enemy(WALKER), MOVING);

			if (Level::dist >= 50)
			{
				createUpgrade++;

				if (spawn > 32 && spawn < 67)
					Level::scene->Add(new Enemy(FLYING), MOVING);

				if (Level::dist >= 100)
				{
					if (spawn > 66)
						Level::scene->Add(new Enemy(JUMPER), MOVING);
				}
			}
		}

		if (createUpgrade == 1)
			Level::scene->Add(new Upgrade(), MOVING);

	}
}

void Spawner::Draw() {}