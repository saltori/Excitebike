#include "Finish.h"
#include "DxLib.h"
#include "ImageMng.h"
constexpr int SlopeAPosY = 375;

Finish::Finish()
{
}

Finish::Finish(int x)
{
	pos = { x, SlopeAPosY };
	HitBox.top = pos.x - 80;
	HitBox.right = pos.x;
	HitBox.bottom = pos.y + 70;
	HitBox.left = pos.y - 15;
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
	HitBox.top = pos.x - 80;
	HitBox.right = pos.x;
	HitBox.bottom = pos.y + 90;
	HitBox.left = pos.y - 20;
	Draw();
}

bool Finish::HitCheck(FVECTOR2 pos)
{
	if (HitBox.top <= pos.x &&HitBox.right >= pos.x
		&&HitBox.left <= pos.y &&HitBox.bottom >= pos.y)
	{
		return true;
	}
	return false;
}

void Finish::HitEffect(float & speed, PL_STATE & state, float & OHValue)
{
	state = PL_STATE::FINISH;
}
