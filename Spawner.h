#ifndef SPAWNER_H
#define SPAWNER_H

#include "Scene.h"
#include "Object.h"
#include "Timer.h"
#include "Enemy.h"
#include "Upgrade.h"
#include "Level.h"
#include "Boss.h"
#include <random>

class Spawner : public Object
{

private:
	float timerF;				//Contagem

	Timer timer;

	uint spawnRate;				//Frequência em que os objetos são instânciados

	int createUpgrade = 0;
	int spawnBoss = 0;

public:
	Spawner();
	~Spawner();

	void Update();
	void Draw();
};

inline void Spawner::Draw()
{

}

#endif // !SPAWNER_H