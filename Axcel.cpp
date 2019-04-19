#include "Axcel.h"
#include "DxLib.h"
#include "ImageMng.h"

constexpr int AxcelPosY = 360;

Axcel::Axcel()
{
}

Axcel::Axcel(int PosX)
{
	pos = { PosX,AxcelPosY };
	HitBox.top = 0;
	HitBox.right = 0;
	HitBox.bottom = 0;
	HitBox.left = 0;
}


Axcel::~Axcel()
{
}

Track_Parts Axcel::GetTrackPartState(void)
{
	return Track_Parts::AXCEL;
}

void Axcel::Draw(void)
{
	DrawRotaGraph(pos.x, pos.y, 2.2f, 0, IMAGE_ID("image/TrakPart/Axcel.png")[0], true);
//	DrawBox(HitBox.top, HitBox.bottom, HitBox.right, HitBox.left, 0x000000, true);
}

square Axcel::GetHitBox(void)
{
	return HitBox;
}

void Axcel::AddPartPos(int speed)
{
	pos.x += speed;
}

void Axcel::Update(void)
{
	HitBox.top = pos.x - 20;
	HitBox.right = pos.x+10;
	HitBox.bottom = pos.y + 15;
	HitBox.left = pos.y - 20;
	Draw();
}

bool Axcel:: Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue)
{
	if (HitBox.top <= pos.x &&HitBox.right >= pos.x
		&&HitBox.left <= pos.y &&HitBox.bottom >= pos.y)
	{
		HitEffect(speed, state, OHValue);
		return true;
	}
	return false;
}

void Axcel::HitEffect(float & speed, PL_STATE &state, float &OHValue)
{
	speed += 5;
	OHValue = OHValue / 2;
}
