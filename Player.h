
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Types.h"
#include "Sprite.h"
#include "Object.h"

class Player : public Object
{
private:
	Sprite* sprite = nullptr;		// Sprite do Player

	// Movimenta��o e Pulo
	float spd = 0;					// Velocidade Geral
	float hSpd = 0;					// Velocidade Horizontal
	float vSpd = 0;					// Velocidade Vertical
	float grav = 0;					// Gravidade

	// Verifica��es
	bool OnGround = false;			// Determina se o Player est� tocando o ch�o

	// Upgrades
	bool DoubleJump = false;		// Determina se o Player est� com upgrade de Pulo Duplo
	int currentJumps = 0;			// Quantidade de pulos atuais
	int maxJumps = 2;				// Quantidade m�xima de pulos

public:
	Player();
	~Player();

	void OnCollision(Object* obj);
	void FloorCollision(Object* obj);

	void Update();
	void Draw();
};

#endif // !_PLAYER_H_
