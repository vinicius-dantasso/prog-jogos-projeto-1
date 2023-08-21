#ifndef SPAWNER_H
#define SPAWNER_H

#include "Scene.h"
#include "Object.h"
#include "Timer.h"

class Spawner : public Object
{

private:
	float timerF;				//Contagem

	Timer timer;

	uint spawnRate;				//Frequ�ncia em que os objetos s�o inst�nciados

	int createUpgrade = 0;
	
public:
	Spawner();
	~Spawner();

	void Update();
	void Draw();
};

#endif // !SPAWNER_H
