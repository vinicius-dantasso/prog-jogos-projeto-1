#include "Spawner.h"
#include "Upgrade.h"
#include <random>

//gerador de n�meros aleat�ris. Usado para delimita��o de intervalo entre os spawns e a escolha do pr�ximo objeto a ser instanciado
std::random_device rd;
std::mt19937 mt(rd());


Spawner::Spawner(Scene * sc, Object * obj) : scene(sc), object(obj)
{
	timer = 1.0f;
}

Spawner::~Spawner()
{
	scene = nullptr;
	object = nullptr;
}

void Spawner::Update()
{
	timer -= 1 * gameTime;

	if (timer < 0)
	{
		timer = mt() % 5;
		scene->Add(new Upgrade(), STATIC);
		
	}
}

void Spawner::Draw() {}