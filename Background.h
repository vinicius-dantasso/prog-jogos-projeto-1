#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Object.h"
#include "Sprite.h"


class Background : public Object
{
private:

	Image * imgF;
	Image * imgB;

	Sprite * bgF1;
	Sprite * bgF2;

	Sprite * bgB1;
	Sprite * bgB2;

	float speed;

	float xB;
	float xF;


public:
	Background();
	~Background();


	void Update();

	void Draw();

};

#endif