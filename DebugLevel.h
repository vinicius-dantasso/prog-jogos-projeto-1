
#ifndef _DEBUG_LEVEL_H_
#define _DEBUG_LEVEL_H_

#include "Game.h"
#include "Scene.h"
#include "Background.h"
#include "Timer.h"


class DebugLevel : public Game
{
private:
	Background* background = nullptr;
	
	Timer timer;

	bool viewBBox = false;

public:
	static Scene* scene;

	void Init();
	void Finalize();
	void Update();
	void Draw();
};

#endif // !_DEBUG_LEVEL_H_