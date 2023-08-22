
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Types.h"
#include "Animation.h"
#include "Object.h"
#include "Engine.h"
#include "GameOver.h"

enum PlayerState {RUNNING, JUMPING, ATTACK, PLAYERIDLE, PLAYERDEAD};

class Player : public Object
{
private:
	TileSet* tiles = nullptr;		// Sprite Sheet do Player
	Animation* anim = nullptr;		// Anima��o do Player

	// Movimenta��o e Pulo
	float spd = 0;					// Velocidade Geral
	float hSpd = 0;					// Velocidade Horizontal
	float vSpd = 0;					// Velocidade Vertical
	float grav = 0;					// Gravidade

	// Verifica��es
	bool OnGround = false;			// Determina se o Player est� tocando o ch�o
	bool isAttacking = true;		// Determina se o Player est� atacando

	// Upgrades
	bool DoubleJump = false;		// Determina se o Player est� com upgrade de Pulo Duplo
	int currentJumps = 0;			// Quantidade de pulos atuais
	int maxJumps = 2;				// Quantidade m�xima de pulos

	// Ataque
	int timer = 0;
	int maxTimer = 25;

public:
	uint state;
	static bool isDead;				// Determina se o Player est� morto

	Player();
	~Player();

	void OnCollision(Object* obj);
	void FloorCollision(Object* obj);

	void Update();
	void Draw();
};

#endif // !_PLAYER_H_
