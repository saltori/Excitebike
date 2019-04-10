#pragma once

#include "VECTOR2.h"
#include <memory>
#include "Player.h"

struct square
{
	int top;
	int bottom;
	int right;
	int left;
};


class Camera
{
public:
	Camera();
	~Camera();
	VECTOR2 &GetPos();
	bool SetPos(VECTOR2 pos);
	bool SetPos(int x, int y);
	bool SetTarget(std::weak_ptr<Player> target);
	void Update(void);	// çXêV
	void Draw(void);
	VECTOR2 GetdefPos(void);
private:
	VECTOR2 pos;
	VECTOR2 defpos;
	std::weak_ptr<Player> target;
	square DrawRange;
};

