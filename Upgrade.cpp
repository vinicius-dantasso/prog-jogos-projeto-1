
#include "FontDemo.h";
#include "Upgrade.h"
#include <cmath>

Upgrade::Upgrade()
{
	sprite = new Sprite("Resources/Upgrade.png");
	spd = -150;
	type = UPGRADE;

	BBox(new Rect(-8, -8, 8, 8));
	MoveTo(window->Width(), window->Height() - 96.0f);
}

Upgrade::~Upgrade()
{
	delete sprite;
}

void Upgrade::OnCollision(Object* obj)
{

}

void Upgrade::Update()
{
	vSpd = sin(time * frequency) * amplitude;
	time++;

	Translate(spd * gameTime, vSpd * gameTime);
}

void Upgrade::Draw()
{
	sprite->Draw(x, y, Layer::FRONT);
}