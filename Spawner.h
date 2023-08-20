#ifndef SPAWNER_H
#define SPAWNER_H

#include "Scene.h"
#include "Object.h"

class Spawner : public Object
{

private:
	Scene * scene = nullptr;
	Object * object;
	float timer;

	
public:
	Spawner(Scene *, Object *);
	~Spawner();

	void Update();
	void Draw();
};

#endif // !SPAWNER_H
