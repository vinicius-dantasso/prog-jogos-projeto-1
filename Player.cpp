
#include "FontDemo.h"
#include "DebugLevel.h"
#include "Player.h"

Player::Player()
{
	tiles = new TileSet("Resources/Player_Run.png", 32, 32, 3, 3);
	anim = new Animation(tiles, 0.12f, true);

	BBox(new Rect(-16, -16, 16, 16));
	MoveTo(48.0f, 672.0f);

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
		DebugLevel::scene->Delete(obj, MOVING);
	}
}

void Player::FloorCollision(Object* obj)
{
	vSpd = 0;
	currentJumps = 0;
	MoveTo(x, obj->Y() - 32);
	OnGround = true;
}

void Player::Update()
{
	int _hDir = -window->KeyDown(VK_LEFT) + window->KeyDown(VK_RIGHT);
	int _jump = window->KeyPress(VK_SPACE);

	// Efeito da gravidade sobre o Player
	vSpd += grav;

	// Pulo caso esteja tocando o chão
	if (_jump && OnGround)
	{
		vSpd -= 620.0f;
		currentJumps++;
		OnGround = false;
		_jump = 0;
	}

	// Pulo duplo caso esteja com o upgrade
	if (!OnGround && DoubleJump && currentJumps < maxJumps)
	{
		if (_jump)
		{
			vSpd = 0;
			vSpd -= 550.0f;
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

	// Manter Player dentro da janela
	/*
	if (x - tiles->Width() / 2.0f < 0)
		MoveTo(tiles->Width() / 2.0f, y);
	else if (x + tiles->Width() / 2.0f > tiles->Width())
		MoveTo(window->Width() - tiles->Width() / 2.0f, y);
	*/
	// Movimento
	hSpd = spd;
	Translate(hSpd * gameTime, vSpd * gameTime);

	// Atualiza animação do Player;
	anim->NextFrame();
}

void Player::Draw()
{
	anim->Draw(x, y, z);
}