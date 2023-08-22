
#ifndef _BOSS_ATTACK_H_
#define _BOSS_ATTACK_H_

#include "Types.h"
#include "Object.h"
#include "Animation.h"
#include "FontDemo.h"
#include "Level.h"

class BossAttack : public Object
{
private:
	TileSet* tile = nullptr;
	Animation* anim = nullptr;

	float spd;

public:
	BossAttack(float posX, float posY);
	~BossAttack();

	void Update();
	void Draw();
};

#endif // !_BOSS_ATTACK_H_