
#include "GameOver.h"

void GameOver::Init()
{
	sprite = new Sprite("Resources/Game_Over.png");
	font = new Font("Resources/m5x7.png");
	font->Spacing(85);
	
	PlaySound(TEXT("Resources/Game_Over_Music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void GameOver::Finalize()
{
	PlaySound(0, 0, 0);
	delete sprite;
	delete font;
}

void GameOver::Update()
{
	if (window->KeyPress(VK_ESCAPE))
		window->Close();

	if (window->KeyPress(VK_RETURN))
		Engine::Next<TitleScreen>();

	if (!canDraw)
	{
		frames++;
		if (frames >= maxFrames)
		{
			frames = 0;
			canDraw = true;
		}
	}
}

void GameOver::Draw()
{
	Color white(1.0f, 1.0f, 1.0f, 1.0f);
	Color black(0.0f, 0.0f, 0.0f, 1.0f);

	if (canDraw)
	{
		font->Draw(window->CenterX() - 168, window->CenterY() + 20, "> Pressione Enter <", black, Layer::UPPER, 0.25f);
		font->Draw(window->CenterX() - 170, window->CenterY() + 20, "> Pressione Enter <", white, Layer::FRONT, 0.25f);

		frames++;
		if (frames >= maxFrames)
		{
			frames = 0;
			canDraw = false;
		}
	}
	sprite->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}