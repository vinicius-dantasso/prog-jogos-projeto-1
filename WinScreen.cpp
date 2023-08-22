
#include "WinScreen.h"

void WinScreen::Init()
{
	sprite = new Sprite("Resources/Win_Screen.png");
	crown = new Sprite("Resources/Capybara_Crown.png");
	font = new Font("Resources/m5x7.png");
	font->Spacing(85);
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
}

void WinScreen::Draw()
{
	Color white(1.0f, 1.0f, 1.0f, 1.0f);
	Color black(0.0f, 0.0f, 0.0f, 1.0f);

	if (canDraw)
	{
		font->Draw(window->CenterX() - 168, window->CenterY() + 120, "> Pressione Enter <", black, Layer::UPPER, 0.25f);
		font->Draw(window->CenterX() - 170, window->CenterY() + 120, "> Pressione Enter <", white, Layer::FRONT, 0.25f);

		frames++;
		if (frames >= maxFrames)
		{
			frames = 0;
			canDraw = false;
		}
	}
	sprite->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}