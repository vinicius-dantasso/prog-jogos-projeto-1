
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
	Animation* anim = nullptr;		// Animação do Player

	// Movimentação e Pulo
	float spd = 0;					// Velocidade Geral
	float hSpd = 0;					// Velocidade Horizontal
	float vSpd = 0;					// Velocidade Vertical
	float grav = 0;					// Gravidade

	// Verificações
	bool OnGround = false;			// Determina se o Player está tocando o chão
	bool isAttacking = true;		// Determina se o Player está atacando

	// Upgrades
	bool DoubleJump = false;		// Determina se o Player está com upgrade de Pulo Duplo
	int currentJumps = 0;			// Quantidade de pulos atuais
	int maxJumps = 2;				// Quantidade máxima de pulos

	// Ataque
	int timer = 0;
	int maxTimer = 25;

public:
	uint state;
	static bool isDead;				// Determina se o Player está morto

	Player();
	~Player();

	void OnCollision(Object* obj);
	void FloorCollision(Object* obj);

	void Update();
	void Draw();
};

#endif // !_PLAYER_H_
