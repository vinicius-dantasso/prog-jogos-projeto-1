#include "Enemy.h"

//enum EnemyTypes{WALKER, FLYING, JUMPER};
Enemy::Enemy(uint Type) {
	switch (Type) {
	case WALKER: 
		break;
	case FLYING: 
		sprite = new TileSet("Resources/Crow.png");
		anim = new Animation(sprite, 0.060f, true);
		uint fly[6] = {11,12,13,14,15,16};

		anim->Add(FLY, fly, 6);
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
	Translate(-speed * gametime, 0);

	// atualiza animação
	anim->Select(state);
	anim->NextFrame();
}

void Enemy::OnCollision(Object* obj) {

}