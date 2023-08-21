
#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Font.h"
#include "Player.h"
#include "Background.h"
#include "Floor.h"
#include "Spawner.h"
#include <Windows.h>
#include <mmsystem.h>
#include <string>

class Level : public Game
{
private:
	Background* background = nullptr;
	Player* player = nullptr;
	Spawner* spawn = nullptr;
	Font* font = nullptr;

public:
	static Scene* scene;
	static int dist;
	int timer = 0;
	int maxTimer = 12;

	void Init();
	void Finalize();
	void Update();
	void Draw();
};

#endif // !_LEVEL_H_
