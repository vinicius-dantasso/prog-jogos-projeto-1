#include "Background.h"

Background::Background()
{
	imgF = new Image("Resources/Foreground.png");
	imgB = new Image("Resources/Background.png");

	bgF1 = new Sprite(imgF);
	bgF2 = new Sprite(imgF);
	bgB1 = new Sprite(imgB);
	bgB2 = new Sprite(imgB);

	speed = 200.0f;
	xB = 0.0f;
	xF = 0.0f;
}

Background::~Background()
{
	delete imgF;
	delete imgB;
	delete bgF1;
	delete bgF2;
	delete bgB1;
	delete bgB2;
}

void Background::Update() 
{
		xB -= 0.25f * speed * gameTime;
		xF -= speed * gameTime;

		if(xB + imgB->Width() < 0)
			xB = 0.0f;
		if(xF + imgF->Width() < 0)
			xF = 0.0f;
		if (Level::dist >= 500)
			speed = 0.0f;
}

void Background::Draw()
{
	bgB1->Draw(xB + imgB->Width() /2, imgB->Height() / 2, Layer::BACK);
	bgB2->Draw((xB + imgB->Width() * 1.5f), imgB->Height() / 2, Layer::BACK);
	bgF1->Draw(xF + imgF->Width() / 2, imgB->Height() * 0.825f, Layer::LOWER);
	bgF2->Draw(xF + imgF->Width() * 1.5f, imgB->Height() * 0.825f, Layer::LOWER);

}