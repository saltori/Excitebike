#include "Finish.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "MapCtl.h"
constexpr int SlopeAPosY = 375;

Finish::Finish()
{
}

Finish::Finish(int x)
{
	pos = { x, SlopeAPosY };
}


Finish::~Finish()
{
}

Track_Parts Finish::GetTrackPartState(void)
{
	return Track_Parts::FNISH;
}

void Finish::Draw(void)
{
	DrawRotaGraph(pos.x, pos.y, 0.87f, 0, IMAGE_ID("image/TrakPart/Finish.png")[0], true);
	//DrawBox(HitBox.top, HitBox.bottom, HitBox.right, HitBox.left, 0x000000, true);
}

square Finish::GetHitBox(void)
{
	return HitBox;
}

void Finish::AddPartPos(int speed)
{
	pos.x += speed;
}

void Finish::Update(void)
{
	HitBox.top = pos.x - 95;
	HitBox.right = pos.x;
	HitBox.bottom = pos.y + 80;
	HitBox.left = pos.y -50;
	Draw();
}

bool Finish:: Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue)
{
	if (HitBox.top <= pos.x &&HitBox.right >= pos.x
		&&HitBox.left <= pos.y &&HitBox.bottom >= pos.y)
	{
		HitEffect(speed, state, OHValue);
		return true;
	}
	return false;
}

void Finish::HitEffect(float & speed, PL_STATE & state, float & OHValue)
{
	state = PL_STATE::FINISH;

}
