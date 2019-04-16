#include "SlopeA.h"
#include"ImageMng.h"
#include "Dxlib.h"

SlopeA::SlopeA()
{

}

SlopeA::SlopeA(VECTOR2 pos)
{
	this->pos = pos;
	HitBox.top = pos.x - 50;
	HitBox.right = pos.x;
	HitBox.bottom = pos.y + 70;
	HitBox.left = pos.y - 40;
}


SlopeA::~SlopeA()
{
}

Track_Parts SlopeA::GetTrackPartState(void)
{
	return Track_Parts::SLOPE_A;
}

void SlopeA::Draw(void)
{
	DrawRotaGraph(pos.x,pos.y,2.2f,0,IMAGE_ID("image/TrakPart/slopeA.png")[0],true);
	DrawBox(HitBox.top, HitBox.bottom, HitBox.right, HitBox.left,0x000000,true);
}

square SlopeA::GetHitBox(void)
{
	return HitBox;
}

void SlopeA::AddPartPos(int speed)
{
	pos.x += speed;
}

void SlopeA::Update(void)
{
	HitBox.top = pos.x - 50;
	HitBox.right = pos.x;
	HitBox.bottom = pos.y + 70;
	HitBox.left = pos.y - 40;
	Draw();
}

bool SlopeA::HitCheck(FVECTOR2 pos)
{
	if (HitBox.top <= pos.x &&HitBox.right >= pos.x
		&&HitBox.left <= pos.y &&HitBox.bottom >= pos.y)
	{
		return true;
	}
	return false;
}
