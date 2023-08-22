
#include "Boss.h"

bool Boss::isDead = false;

Boss::Boss()
{
	tiles = new TileSet("Resources/Wolf_Sheet.png", 120, 86, 7, 33);
	anim = new Animation(tiles, 0.2f, true);
	
	uint SeqWalk[6] = { 21,22,23,24,25,26 };
	uint SeqAttack[7] = { 7,8,9,10,11,12,13 };
	uint SeqWoof[7] = { 14,15,16,17,18,19,20 };
	uint SeqIdle[7] = { 0,1,2,3,4,5,6 };
	uint SeqTired[5] = { 28,29,30,31,32 };

	anim->Add(BOSSIDLE, SeqIdle, 7);
	anim->Add(BOSSATTACK, SeqAttack, 7);
	anim->Add(BOSSWOOF, SeqWoof, 7);
	anim->Add(BOSSWALK, SeqWalk, 6);
	anim->Add(BOSSTIRED, SeqTired, 5);
	
	BBox(new Rect(-43, -32, 60, 43));
	MoveTo(window->Width() + 120, window->Height() - 92);

	type = BOSS;
	state = BOSSWALK;
	hSpd = -150;

	font = new Font("Resources/m5x7.png");
	font->Spacing(85);
}

Boss::~Boss()
{
	delete tiles;
	delete anim;
	delete font;
}

void Boss::OnCollision(Object* obj)
{
	if (state == BOSSTIRED && obj->Type() == PLAYER)
	{
		life--;
	}
	else if (state != BOSSTIRED && obj->Type() == PLAYER)
	{
		Level::scene->Delete(obj, MOVING);
	}
}

void Boss::Update()
{
	switch (state)
	{
	case BOSSIDLE:
		timer++;
		if (timer >= 24)
		{
			timer = 0;
			state = BOSSATTACK;
		}

		break;

	case BOSSATTACK:
		timer++;
		if (timer >= maxTimer)
		{
			timer = 0;
			attackCount++;
			if (attackCount < 4)
			{
				Level::scene->Add(new BossAttack(this->X() - 60, this->Y() + 20), MOVING);
				state = BOSSIDLE;
			}
			else
			{
				attackCount = 0;
				state = BOSSTIRED;
			}
		}
		break;

	case BOSSWOOF:
		timer++;
		if(timer >= maxTimer)
		{
			timer = 0;
			playMusic = true;
			state = BOSSIDLE;
		}
		break;

	case BOSSWALK:
		if (x >= window->Width() - 100)
			Translate(hSpd * gameTime, 0.0f);
		else
		{
			if (anim->Frame() == 26)
			{
				PlaySound(TEXT("Resources/Wolf_Howl.wav"), NULL, SND_FILENAME | SND_ASYNC);
				state = BOSSWOOF;
			}
		}
		break;

	case BOSSTIRED:
		timer++;
		if (timer >= maxTimer*3)
		{
			timer = 0;
			state = BOSSIDLE;
		}
		break;
	}

	if (playMusic)
	{
		playMusic = false;
		PlaySound(TEXT("Resources/Level_Music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	if (life <= 0)
	{
		isDead = true;
		Level::scene->Delete(this, MOVING);
	}

	if (window->KeyPress(VK_RETURN))
		isDead = true;

	anim->Select(state);
	anim->NextFrame();
}

void Boss::Draw()
{
	anim->Draw(x, y, z);
}