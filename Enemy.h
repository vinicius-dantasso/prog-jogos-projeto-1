#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Types.h"
#include "Sprite.h"
#include "Animation.h"
#include "Object.h"
#include "Player.h"

enum EnemyTypes{WALKER, FLYING, JUMPER};
enum States{IDLE, WALK, ATACKING};

class Enemy : public Object {
private:
	Sprite* sprite = nullptr;		//Sprite do Inimigo
	Sprite* shooting = nullptr;		//Sprite para disparo do inimigo (para inimigos que necessitam)
	TileSet* tiles = nullptr;		//Tileset
	Animation* anim = nullptr;		//Animação
	Player* player = nullptr;		//Ponteiro para o objeto player

public:

	uint state; //Estado do Inimigo

	Enemy();
	~Enemy();

	void Update();
	void OnCollision(Object* obj);
	void Draw();



};

inline void Enemy::Draw() {
	anim->Draw(x, y, z);
}

#endif