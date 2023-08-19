#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Types.h"
#include "Sprite.h"
#include "Animation.h"
#include "Object.h"
#include "Player.h"

enum EnemyTypes{WALKER, FLYING, JUMPER};
enum States{IDLE, WALK, ATACKING, FLY};

class Enemy : public Object 
{
private:
	TileSet* sprite = nullptr;		//Folha do Inimigo
	TileSet* shooting = nullptr;	//Folha para disparo do inimigo (para inimigos que necessitam)
	Animation* anim = nullptr;		//Animação
	Player* player = nullptr;		//Ponteiro para o objeto player

	float speed;					//Velocidade do Inimigo

public:

	uint state; //Estado do Inimigo

	Enemy(uint state);
	~Enemy();

	void Update();
	void OnCollision(Object* obj);
	void Draw();



};

inline void Enemy::Draw() {
	anim->Draw(x, y, z);
}

#endif