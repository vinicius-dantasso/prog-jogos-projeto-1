
#ifndef _UPGRADE_H_
#define _UPGRADE_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

class Upgrade : public Object
{
private:
	Sprite* sprite = nullptr;
	int spd = 0;

public:
	Upgrade();
	~Upgrade();

	void OnCollision(Object* obj);

	void Update();
	void Draw();
};

#endif // !_UPGRADE_H_
