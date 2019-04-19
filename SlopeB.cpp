#include "SlopeB.h"
#include "Dxlib.h"
#include "ImageMng.h"
#include "MapCtl.h"
constexpr int SlopeAPosY = 360;

SlopeB::SlopeB()
{
}

SlopeB::SlopeB(int x)
{
	this->pos = {x,SlopeAPosY};
	HitBox.top = pos.x - 80;
	HitBox.right = pos.x;
	HitBox.bottom = pos.y + 70;
	HitBox.left = pos.y - 15;
}


SlopeB::~SlopeB()
{
}

Track_Parts SlopeB::GetTrackPartState(void)
{
	return Track_Parts::SLOPE_B;
}

void SlopeB::Draw(void)
{

	DrawRotaGraph(pos.x, pos.y, 2.2f, 0, IMAGE_ID("image/TrakPart/slopeB.png")[0], true);
	
}

square SlopeB::GetHitBox(void)
{
	return HitBox;
}

void SlopeB::AddPartPos(int speed)
{
	pos.x += speed;
}

void SlopeB::Update(void)
{
	HitBox.top = pos.x - 80;
	HitBox.right = pos.x;
	HitBox.bottom = pos.y + 90;
	HitBox.left = pos.y - 20;
	Draw();
}

bool SlopeB:: Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue)
{
	if (HitBox.top <= pos.x &&HitBox.right >= pos.x
		&&HitBox.left <= pos.y &&HitBox.bottom >= pos.y)
	{
		HitEffect(speed, state, OHValue);
		return true;
	}
	return false;
}

void SlopeB::HitEffect(float & speed, PL_STATE &state, float &OHValue)
{
	state = PL_STATE::JUMP;
	lpMapCtl.AddRoadpos({ speed,0 });
	lpMapCtl.AddWallpos({ speed,0 });
}
