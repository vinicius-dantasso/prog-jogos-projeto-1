
#include "FontDemo.h";
#include "Upgrade.h"

Upgrade::Upgrade()
{
	sprite = new Sprite("Resources/Upgrade.png");
	spd = -150;
	type = UPGRADE;

	BBox(new Rect(-8, -8, 8, 8));
	MoveTo(window->Width(), window->Height() - 48.0f);
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
	Translate(spd * gameTime, 0.0f);
}

void Upgrade::Draw()
{
	sprite->Draw(x, y, z);
}