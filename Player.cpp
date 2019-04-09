#include "Player.h"
#include "DxLib.h"
#include "ImageMng.h"


Player::Player()
{
	speed = 10;
}


Player::Player(VECTOR2 pos)
{
	this->pos = pos;
}

Player::~Player()
{
}

void Player::Draw(std::string filename, VECTOR2 divSize, VECTOR2 divCnt, VECTOR2 chipOffset)
{
	ImageMng::GetInstance().GetID(filename,divSize,divCnt,chipOffset);
	
}

void Player::SetMove(void)
{
	GetHitKeyStateAll(key);

	if (key[KEY_INPUT_D])
	{
		pos.x -= speed;
	}
}


