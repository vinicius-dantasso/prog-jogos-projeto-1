
#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Font.h"
#include "Player.h"
#include "Background.h"
#include "Floor.h"

class Level : public Game
{
private:
	Background* background = nullptr;
	Player* player = nullptr;

public:
	static Scene* scene;

	void Init();
	void Finalize();
	void Update();
	void Draw();
};

#endif // !_LEVEL_H_
