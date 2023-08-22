
#include "Instructions.h"

void Instructions::Init()
{
	sprite = new Sprite("Resources/Tutorial.png");
	font = new Font("Resources/m5x7.png");
	font->Spacing(85);
}

void Instructions::Finalize()
{
	delete sprite;
	delete font;
}

void Instructions::Update()
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

void Instructions::Draw()
{
	Color white(1.0f, 1.0f, 1.0f, 1.0f);
	Color black(0.0f, 0.0f, 0.0f, 1.0f);

	if (canDraw)
	{
		font->Draw(window->CenterX() - 118, window->CenterY() - 120, "> Pressione Enter <", black, Layer::UPPER, 0.15f);
		font->Draw(window->CenterX() - 120, window->CenterY() - 120, "> Pressione Enter <", white, Layer::FRONT, 0.15f);

		frames++;
		if (frames >= maxFrames)
		{
			frames = 0;
			canDraw = false;
		}
	}
	sprite->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}