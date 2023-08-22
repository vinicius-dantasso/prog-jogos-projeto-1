
#ifndef _BOSS_H_
#define _BOSS_H_

#include "Object.h"
#include "Animation.h"
#include "Types.h"
#include "FontDemo.h"
#include "Level.h"
#include "Font.h"
#include "BossAttack.h"
#include <Windows.h>
#include <mmsystem.h>
#include <string>

enum BossState {BOSSWALK, BOSSATTACK, BOSSTIRED, BOSSIDLE, BOSSWOOF};

class Boss : public Object
{
private:
	TileSet* tiles = nullptr;
	Animation* anim = nullptr;
	Font* font = nullptr;

	float spd = 0;
	float hSpd = 0;

	int attackCount = 0;
	int attackMax = 3;
	int life = 150;
	bool damage = false;

	int timer = 0;
	int maxTimer = 80;

	bool playMusic = false;

public:
	uint state;
	static bool isDead;

	Boss();
	~Boss();

	void OnCollision(Object* obj);

	void Update();
	void Draw();
};

#endif // !_BOSS_H_
