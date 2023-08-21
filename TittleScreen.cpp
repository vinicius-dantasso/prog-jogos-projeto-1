
#include "TitleScreen.h"

void TitleScreen::Init()
{
	sprite = new Sprite("Resources/Title_Screen.png");
	font = new Font("Resources/m5x7.png");
	font->Spacing(85);

	PlaySound(TEXT("Resources/Back_Music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void TitleScreen::Finalize()
{
	delete sprite;
	delete font;
	PlaySound(0, 0, 0);
}

void TitleScreen::Update()
{
	if (window->KeyPress(VK_ESCAPE))
		window->Close();

	if (window->KeyPress(VK_RETURN))
		Engine::Next<Level>();

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

void TitleScreen::Draw()
{
	Color white (1.0f, 1.0f, 1.0f, 1.0f);
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