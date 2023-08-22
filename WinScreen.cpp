
#include "WinScreen.h"

void WinScreen::Init()
{
	sprite = new Sprite("Resources/Win_Screen.png");
	crown = new Sprite("Resources/Capybara_Crown.png");

	font = new Font("Resources/m5x7.png");
	font->Spacing(85);

	PlaySound(TEXT("Resources/Win_Music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void WinScreen::Finalize()
{
	delete sprite;
	delete crown;
	delete font;
}

void WinScreen::Update()
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

	time++;
	posY = (window->CenterY() - 200) + sin(time * frequency) * amplitude;
}

void WinScreen::Draw()
{
	Color white(1.0f, 1.0f, 1.0f, 1.0f);
	Color black(0.0f, 0.0f, 0.0f, 1.0f);

	font->Draw(window->CenterX() - 168, window->CenterY() + 220, "> Pressione Enter <", black, Layer::UPPER, 0.25f);
	font->Draw(window->CenterX() - 170, window->CenterY() + 220, "> Pressione Enter <", white, Layer::FRONT, 0.25f);

	crown->Draw(window->CenterX(), posY, Layer::BACK);
	sprite->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}