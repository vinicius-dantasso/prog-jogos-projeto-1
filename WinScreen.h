
#ifndef _WIN_SCREEN_H_
#define _WIN_SCREEN_H_

#include "Game.h"
#include "Sprite.h"
#include "Engine.h"
#include "Level.h"
#include "Font.h"
#include <Windows.h>
#include <mmsystem.h>

class WinScreen : public Game
{
private:
	Sprite* sprite = nullptr;
	Sprite* crown = nullptr;
	Font* font = nullptr;

	int frames = 0;
	int maxFrames = 25;
	bool canDraw = false;

public:
	void Init();
	void Finalize();
	void Update();
	void Draw();
};

#endif // !_WIN_SCREEN_H_
