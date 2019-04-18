#include "Swamp.h"
#include "Dxlib.h"
#include "ImageMng.h"
constexpr int AxcelPosY = 389;

Swamp::Swamp()
{

}

Swamp::Swamp(int x)
{
	pos = { x,AxcelPosY };
}


Swamp::~Swamp()
{
}

Track_Parts Swamp::GetTrackPartState(void)
{
	return Track_Parts::SWAMP;
}

void Swamp::Draw(void)
{
	DrawRotaGraph(pos.x, pos.y, 2.2f, 0, IMAGE_ID("image/TrakPart/swamp.png")[0], true);
	//DrawBox(HitBox.top, HitBox.bottom, HitBox.right, HitBox.left, 0x000000, true);
	//DrawBox(HitBox2.top, HitBox2.bottom, HitBox2.right, HitBox2.left, 0xffffff, true);
}

square Swamp::GetHitBox(void)
{
	return HitBox;
}

void Swamp::AddPartPos(int speed)
{
	pos.x += speed;
}

void Swamp::Update(void)
{
	HitBox.top = pos.x - 20;
	HitBox.right = pos.x + 20;
	HitBox.bottom = pos.y -30;
	HitBox.left = pos.y - 60;

	HitBox2.top = pos.x + 20;
	HitBox2.right = pos.x - 20;
	HitBox2.bottom = pos.y - 10;
	HitBox2.left = pos.y + 20;

	Draw();
}

bool Swamp::HitCheck(FVECTOR2 pos)
{
	bool rtnFlag = false;
	if (HitBox.top <= pos.x &&HitBox.right >= pos.x
 		&&HitBox.left <= pos.y &&HitBox.bottom >= pos.y)
	{
		rtnFlag = true;
	}
	if (HitBox2.top >= pos.x &&HitBox2.right <= pos.x
		&&HitBox2.left >= pos.y &&HitBox2.bottom <= pos.y)
	{
		rtnFlag = true;
	}
	return rtnFlag;
}

void Swamp::HitEffect(float & speed, PL_STATE & state, float & OHValue)
{
	speed -= 3;
}
