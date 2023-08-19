
#ifndef _DEBUG_LEVEL_H_
#define _DEBUG_LEVEL_H_

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

class DebugLevel : public Game
{
private:
	Sprite* background = nullptr;
	bool viewBBox = false;

public:
	static Scene* scene;

	void Init();
	void Finalize();
	void Update();
	void Draw();
};

#endif // !_DEBUG_LEVEL_H_