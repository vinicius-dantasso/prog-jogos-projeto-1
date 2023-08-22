#include "Spawner.h"

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

		spawnRate = 1 + mt() % timeRate;

		uint spawn = mt() % 100;

		if ((Level::dist <= 50 || Level::dist > 50) && spawnBoss < 1)
		{
			if (spawn < 40)
				Level::scene->Add(new Enemy(WALKER), MOVING);

			if (Level::dist >= 50)
			{
				if (createUpgrade < 2)
					createUpgrade++;

				if (spawn > 30 && spawn < 67)
					Level::scene->Add(new Enemy(FLYING), MOVING);

				if (Level::dist >= 100)
				{
					if (spawn > 60)
						Level::scene->Add(new Enemy(JUMPER), MOVING);
				}
			}
		}

		if (Level::dist >= 300 && spawnBoss < 2)
			spawnBoss++;

		if (createUpgrade == 1)
			Level::scene->Add(new Upgrade(), MOVING);

		if (spawnBoss == 1)
		{
			Level::scene->Add(new Boss(), MOVING);
		}

	}
}
