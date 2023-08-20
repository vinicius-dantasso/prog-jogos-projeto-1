#include "FontDemo.h"
#include "Enemy.h"
#include "DebugLevel.h"
#include <cmath>

//enum EnemyTypes{WALKER, FLYING, JUMPER};
Enemy::Enemy(uint Type) {
	uint fly[2] = { 8,9 };
	uint obstacle[1] = { 1 };
	uint jumperGround[1] = { 1 };
	uint jumperJump[1] = { 0 };

	enemyType = Type;

	switch (enemyType) {
	case WALKER:
		sprite = new TileSet("Resources/Box.png", 32, 32, 1, 1);
		anim = new Animation(sprite, 1.0f, false);

		anim->Add(WALK, obstacle, 1);
		state = WALK;
		speed = -150;

		BBox(new Rect(-16, -16, 16, 16));
		MoveTo(window->Width() + 48, window->Height() - 48);
		break;
	case FLYING: 
		sprite = new TileSet("Resources/Crow_Enemy.png", 48, 32, 4, 4);
		anim = new Animation(sprite, 0.12f, true);

		anim->Add(FLY, fly, 2);
		state = FLY;
		speed = -150;

		BBox(new Rect(-16, -16, 16, 16));
		MoveTo(window->Width() + 48, window->CenterY() - 50);
		break;
	case JUMPER:
		sprite = new TileSet("Resources/Frog.png", 16, 32, 2, 2);
		anim = new Animation(sprite, 0.12f, false);

		anim->Add(IDLE, jumperGround, 1);
		anim->Add(ATACKING, jumperJump, 1);
		state = IDLE;
		speed = -150;

		BBox(new Rect(-8, -4, 8, 16));
		MoveTo(window->Width() + 16, window->Height() - 32);
		break;
	}

	type = ENEMY;
}

Enemy::~Enemy() {
	delete sprite;
	delete anim;
}

void Enemy::Update() {
	switch (state)
	{
	case FLY:
		vSpd = sin(time * frequency) * amplitude;
		time++;

		Translate(speed * gameTime, vSpd * gameTime);
		break;
	case WALK:
		Translate(speed * gameTime, 0.0f);
		break;
	case IDLE:
		vSpd += grav;

		timer++;
		if (timer >= maxTimer && onGround)
		{
			timer = 0;
			vSpd -= 620.0f;
			onGround = false;
		}

		Translate(speed * gameTime, vSpd * gameTime);
		break;
	}

	// Deletar Inimigo caso saia da janela
	if (x < 0)
		DebugLevel::scene->Delete(this, MOVING);

	// atualiza anima��o
	if (this->enemyType != JUMPER)
		anim->Select(state);
	else if (onGround)
		anim->Select(IDLE);
	else if (!onGround)
		anim->Select(ATACKING);

	anim->NextFrame();
}

void Enemy::OnCollision(Object* obj) {
	if (obj->Type() == FLOOR && this->enemyType == JUMPER)
	{
		vSpd = 0;
		MoveTo(x, obj->Y() - 32);
		onGround = true;
		state = IDLE;
	}
}
