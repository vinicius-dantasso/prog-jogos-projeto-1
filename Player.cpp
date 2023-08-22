
#include "FontDemo.h"
#include "Level.h"
#include "Player.h"

bool Player::isDead = false;

Player::Player()
{
	tiles = new TileSet("Resources/Player_Teste.png", 33, 32, 5, 11);
	anim = new Animation(tiles, 0.12f, true);

	uint SeqRun[5] = { 4,3,2,1,0 };
	uint SeqAttack[5] = { 5,6,7,8,9 };
	uint SeqJump[1] = { 10 };

	anim->Add(RUNNING, SeqRun, 5);
	anim->Add(ATTACK, SeqAttack, 5);
	anim->Add(JUMPING, SeqJump, 1);

	BBox(new Rect(-8, -8, 8, 16));
	MoveTo(48.0f, window->Height() - 100.0f);

	grav = 20.0f;
	type = PLAYER;
	state = RUNNING;
}

Player::~Player()
{
	delete anim;
	delete tiles;
}

void Player::OnCollision(Object* obj)
{
	if (obj->Type() == FLOOR)
		FloorCollision(obj);

	if (obj->Type() == UPGRADE)
	{
		DoubleJump = true;
		Level::scene->Delete(obj, MOVING);
	}

	if (obj->Type() == ENEMY && state != ATTACK)
	{
		isDead = true;
		Level::scene->Delete(this, MOVING);
	}

	else if (obj->Type() == ENEMY && state == ATTACK)
		Level::scene->Delete(obj, MOVING);
}

void Player::FloorCollision(Object* obj)
{
	vSpd = 0;
	currentJumps = 0;
	MoveTo(x, obj->Y() - 32);
	if (state != ATTACK)
		state = RUNNING;
	OnGround = true;
}

void Player::Update()
{
	int _hDir = -window->KeyDown(VK_LEFT) + window->KeyDown(VK_RIGHT);
	int _jump = window->KeyPress(VK_UP);
	int _attack = window->KeyPress(VK_SPACE);
	bool _levelDist = Level::dist >= 20;

	// Efeito da gravidade sobre o Player
	vSpd += grav;

	// Pulo caso esteja tocando o chão
	if (_jump && OnGround)
	{
		vSpd -= 420.0f;
		currentJumps++;
		OnGround = false;
		state = JUMPING;
		_jump = 0;
	}

	// Pulo duplo caso esteja com o upgrade
	if (!OnGround && DoubleJump && currentJumps < maxJumps)
	{
		if (_jump)
		{
			vSpd = 0;
			vSpd -= 450.0f;
			currentJumps++;
		}
	}

	// Movimentação Horizontal
	switch (_hDir)
	{
	case -1:
		spd = -150.0f;
		break;

	case 1:
		spd = 250.0f;
		break;

	default:
		spd = 0.0f;
		break;
	}

	// Ataque
	if (_attack && OnGround)
		state = ATTACK;

	switch (state)
	{
	case ATTACK:
		BBox(new Rect(-16, -16, 32, 16));

		timer++;
		if (timer >= maxTimer && OnGround)
		{
			timer = 0;
			state = RUNNING;
			BBox(new Rect(-8, -8, 8, 16));
		}
		else if (timer >= maxTimer && !OnGround)
		{
			timer = 0;
			state = JUMPING;
			BBox(new Rect(-8, -8, 8, 16));
		}
		break;
	}

	// Manter Player dentro da janela
	if (x - tiles->Width() / 6.0f < 0)
		MoveTo(tiles->Width() / 6.0f, y);
	else if (x + tiles->Width() / 6.0f > window->Width())
		MoveTo(window->Width() - tiles->Width() / 6.0f, y);

	// Movimento
	hSpd = spd;
	Translate(hSpd * gameTime, vSpd * gameTime);

	// Atualiza animação do Player;
	anim->Select(state);
	anim->NextFrame();
}

void Player::Draw()
{
	anim->Draw(x, y, Layer::FRONT);
}