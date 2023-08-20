
#include "FontDemo.h"
#include "Floor.h"

Floor::Floor()
{
	sprite = new Sprite("Resources/Wall.png");

	BBox(new Rect(-18, -18, 18, 18));
	type = FLOOR;
}

Floor::~Floor()
{
	delete sprite;
}

void Floor::Update()
{

}

void Floor::Draw()
{
	sprite->Draw(x, y, Layer::UPPER);
}