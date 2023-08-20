
#ifndef _FLOOR_TILE_H_
#define _FLOOR_TILE_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

class Floor : public Object
{
private:
	Sprite* sprite = nullptr;

public:
	Floor();
	~Floor();

	void Update();
	void Draw();
};

#endif // !_FLOOR_TILE_H_
