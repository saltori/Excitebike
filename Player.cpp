#include "Player.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"

#define PLAYER_DEF_SPEED (5)

Player::Player()
{

}


Player::Player(VECTOR2 pos)
{
	this->pos = pos;
	speed = PLAYER_DEF_SPEED;
	state = PL_STATE::STOP;
}

Player::~Player()
{
}

void Player::Init(std::string filename, VECTOR2 divSize, VECTOR2 divCnt, VECTOR2 chipOffset)
{
	ImageMng::GetInstance().GetID(filename,divSize,divCnt,chipOffset);
	imageName			= filename;
	this->divSize		= divSize;
	this->divCnt		= divCnt;
	this->chipOffset	= chipOffset;
}

void Player::Draw(void)
{
	if (imageName.length() == 0)
	{
		return;
	}
	DrawRotaGraph(pos.x, pos.y,2,0, IMAGE_ID(imageName)[chipOffset.x + divCnt.x * chipOffset.y], true);
}

void Player::SetMove(void)
{
	GetHitKeyStateAll(key);
	if (key[KEY_INPUT_A])
	{
		pos.x -= speed;
	}
	if (pos.x >= lpSceneTask.GetScreenSize().x / 2)
	{
	}
	else
	{
		if (key[KEY_INPUT_D])
		{
			pos.x += speed;
		}
	}

}

const VECTOR2 & Player::GetPos(void)
{
	return pos;
}


