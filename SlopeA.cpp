#include "SlopeA.h"
#include"ImageMng.h"
#include "Dxlib.h"
#include "MapCtl.h"
constexpr int SlopeAPosY = 380;

SlopeA::SlopeA()
{

}

SlopeA::SlopeA(int x)
{
	this->pos = {x,SlopeAPosY};
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
	//DrawBox(HitBox.top, HitBox.bottom, HitBox.right, HitBox.left, 0x000000, true);
	DrawRotaGraph(pos.x,pos.y,2.2f,0,IMAGE_ID("image/TrakPart/slopeA.png")[0],true);
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

bool SlopeA:: Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue)
{
	if (HitBox.top <= pos.x &&HitBox.right >= pos.x
		&&HitBox.left <= pos.y &&HitBox.bottom >= pos.y)
	{
		HitEffect(speed, state, OHValue);
		return true;
	}
	return false;
}

void SlopeA::HitEffect(float & speed, PL_STATE &state, float &OHValue)
{
	state = PL_STATE::JUMP;
	lpMapCtl.AddRoadpos({ speed,0 });
	lpMapCtl.AddWallpos({ speed,0 });
}
