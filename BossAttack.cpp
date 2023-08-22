
#include "BossAttack.h"

BossAttack::BossAttack(float posX, float posY)
{
	tile = new TileSet("Resources/Wolf_Attack.png", 64, 64, 3, 3);
	anim = new Animation(tile, 0.5f, false);

	BBox(new Rect(-5, -10, 15, 25));
	MoveTo(posX, posY);

	spd = -180.0f;
	type = ENEMY;
}

BossAttack::~BossAttack()
{
	delete tile;
	delete anim;
}

void BossAttack::Update()
{
	if (x < 0)
		Level::scene->Delete(this, MOVING);

	Translate(spd * gameTime, 0.0f);
	anim->NextFrame();
}

void BossAttack::Draw()
{
	anim->Draw(x, y, Layer::UPPER);
}