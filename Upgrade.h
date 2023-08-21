
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
	float vSpd = 0;
	float frequency = 0.03;			//Frequência de Onda Senoide
	int amplitude = 30;				//Amplitude de Onda
	int time = 0;					//Duração da Onda

public:
	Upgrade();
	~Upgrade();

	void OnCollision(Object* obj);

	void Update();
	void Draw();
};

#endif // !_UPGRADE_H_
