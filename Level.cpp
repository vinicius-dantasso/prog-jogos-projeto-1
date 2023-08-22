
#include "Level.h"

Scene* Level::scene = nullptr;
int Level::dist = 0;

void Level::Init()
{
	scene = new Scene();
	Level::dist = 0;

	Background* background = new Background();
	scene->Add(background, STATIC);

	Player* player = new Player();
	scene->Add(player, MOVING);

	Floor* floor;
	float offSetX = 16.0f;
	float offSetY = 32.0f;

	for (int i = 1; i <= 46; i += 2)
	{
		floor = new Floor();
		floor->MoveTo(offSetX * i, window->Height() - offSetY);
		scene->Add(floor, STATIC);
	}

	Spawner* spawner = new Spawner();
	scene->Add(spawner, STATIC);

	font = new Font("Resources/m5x7.png");
	font->Spacing(85);

	PlaySound(TEXT("Resources/Level_Music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Level::Finalize()
{
	PlaySound(0, 0, 0);
	delete font;
	delete scene;
}

void Level::Update()
{
	timer++;
	if (timer >= maxTimer)
	{
		timer = 0;
		dist++;
	}

	if (Player::isDead)
	{
		Player::isDead = false;
		Engine::Next<GameOver>();
	}
	else if (Boss::isDead)
	{
		Boss::isDead = false;
		Engine::Next<WinScreen>();
	}
	else
	{
		scene->Update();
		scene->CollisionDetection();
	}
}

void Level::Draw()
{
	Color white (1.0f, 1.0f, 1.0f, 1.0f);
	Color black (0.0f, 0.0f, 0.0f, 1.0f);

	std::string strDist = std::to_string(dist);
	font->Draw(window->Width() - 80, 30, strDist, white, Layer::FRONT, 0.15f);
	font->Draw(window->Width() - 75, 31, strDist, black, Layer::UPPER, 0.15f);

	scene->Draw();
	//scene->DrawBBox();
}