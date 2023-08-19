#include "Enemy.h"

//enum EnemyTypes{WALKER, FLYING, JUMPER};
Enemy::Enemy(uint Type) {
	uint fly[5] = { 10,9,16,15,14 };
	switch (Type) {
	case WALKER: 
		break;
	case FLYING: 
		sprite = new TileSet("Resources/Crow.png");
		anim = new Animation(sprite, 0.060f, true);

		anim->Add(FLY, fly, 5);
		state = FLY;
		speed = 200;

		MoveTo(window->CenterX(), window->CenterY());
		break;
	case JUMPER: 
		break;
	default: 
		break;
	}
}

Enemy::~Enemy() {
	delete sprite;
	delete anim;
}

void Enemy::Update() {
	Translate(-speed * gameTime, 0);

	// atualiza anima��o
	anim->Select(state);
	anim->NextFrame();
}

void Enemy::OnCollision(Object* obj) {

}