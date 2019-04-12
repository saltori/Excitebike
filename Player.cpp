#include "Player.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "MapCtl.h"
#include "FontMng.h"
constexpr int PlayerDefSpeed = 10;
constexpr int DefaultEngine = 350;
constexpr unsigned int EngineLimiter = 466;
Player::Player()
{

}


Player::Player(VECTOR2 pos)
{
	this->pos = pos;
	speed = PlayerDefSpeed;
	state = PL_STATE::STOP;
	engineBox.top		= 350;
	engineBox.bottom	= 580;
	engineBox.right		= DefaultEngine;
	engineBox.left		= 520;
	OHValue				= 0;
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
	initAnim();
}

void Player::Draw(void)
{
	
	DrawBox(engineBox.top, engineBox.left, engineBox.right + OHValue, engineBox.bottom, 0xFF0000, true);
	DrawRotaGraph(lpSceneTask.GetScreenSize().x / 2, 547, 1.7, 0, IMAGE_ID("image/engine.png")[0], true);


	int id = 0;

	if (!(animTable.find(animName) == animTable.end()))
	{
		id = animTable[animName][static_cast<int>(ANIM_TBL::START_ID)] + (animCnt / animTable[animName][static_cast<int>(ANIM_TBL::INV)]%animTable[animName][static_cast<int>(ANIM_TBL::FRAME)]);
	}

	DrawRotaGraph(pos.x, pos.y,2,0, IMAGE_ID(imageName)[id], true);


}

void Player::SetMove(void)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);
	if (OHValue != 0)
	{
		OHValue--;
	}
	if (pos.x >= lpSceneTask.GetScreenSize().x / 2)
	{
		if ((engineBox.right + OHValue) >= EngineLimiter)
		{

		}
		else
		{
			if (key[KEY_INPUT_A])
			{
				lpMapCtl.AddRoadpos({ speed / 2,0 });
				lpMapCtl.AddWallpos({ speed / 2,0 });
				OHValue++;
			}
			else if (key[KEY_INPUT_S])
			{
				lpMapCtl.AddRoadpos({ speed,0 });
				lpMapCtl.AddWallpos({ speed,0 });
				if ((engineBox.right + OHValue) <= EngineLimiter)
				{
					OHValue += 2;
				}
			}
			else {}

			if ((key[KEY_INPUT_A] && !keyOld[KEY_INPUT_A]) || (key[KEY_INPUT_S] && !keyOld[KEY_INPUT_S]))
			{
				SetAnim("走");
				state = PL_STATE::RUN;
			}
			if (key[KEY_INPUT_DOWN] && !keyOld[KEY_INPUT_DOWN])
			{
				SetAnim("右");
			}
			if (key[KEY_INPUT_DOWN])
			{
				pos.y += speed / 2;

			}
			if (key[KEY_INPUT_UP] && !keyOld[KEY_INPUT_UP])
			{
				SetAnim("左");
			}
			if (key[KEY_INPUT_UP])
			{
				pos.y -= speed / 2;
			}

			if (key[KEY_INPUT_RIGHT] && !keyOld[KEY_INPUT_RIGHT])
			{
				SetAnim("ウィリー");
				state = PL_STATE::WHEELIE;
			}

		}


	}
	else
	{
		if (key[KEY_INPUT_A])
		{
			pos.x += speed/2;
			if ((engineBox.right + OHValue) <= EngineLimiter)
			{
				OHValue ++;
			}
		}
		if (key[KEY_INPUT_S])
		{
			pos.x += speed;
			if ((engineBox.right + OHValue) <= EngineLimiter)
			{
				OHValue += 2;
			}
		}
	}



	if (key[KEY_INPUT_E] && !keyOld[KEY_INPUT_E])
	{
		SetAnim("着地");
	}

	if (key[KEY_INPUT_Z] && !keyOld[KEY_INPUT_Z])
	{
		SetAnim("逆");
	}

	if (key[KEY_INPUT_F] && !keyOld[KEY_INPUT_F])
	{
		SetAnim("足");
	}

	if (key[KEY_INPUT_X] && !keyOld[KEY_INPUT_X])
	{
		SetAnim("起");
	}




	animCnt++;
}

const VECTOR2 & Player::GetPos(void)
{
	return pos;
}

const int Player::GetplayerSpeed(void)
{
	return PlayerDefSpeed;
}

bool Player::SetAnim(std::string animName)
{
	if (animTable.find(animName) == animTable.end())
	{
		return false;
	}
	if (this->animName != animName)
	{
		animCnt = 0;
		this->animName = animName;
	}
	return true;
}

void Player::AddanimCnt(int aniCnt)
{
	this->animCnt += aniCnt;
}

bool Player::AddAnim(std::string animName, int id_x, int id_y, int frame, int inv)
{
	animTable[animName][static_cast<int>(ANIM_TBL::START_ID)]	= id_x + id_y * divCnt.x;
	animTable[animName][static_cast<int>(ANIM_TBL::FRAME)]		= frame;
	animTable[animName][static_cast<int>(ANIM_TBL::INV)]		= inv;
	return true;
}

bool Player::initAnim(void)
{
	AddAnim("止", 1, 0, 1, 1);
	AddAnim("走",1,0,2,3);
	AddAnim("左", 3, 0, 1, 5);
	AddAnim("右", 4, 0, 1, 5);
	AddAnim("ウィリー", 0, 1, 5, 8);
	AddAnim("着地", 0, 2, 3, 10);
	AddAnim("逆", 0, 3, 4, 10);
	AddAnim("足", 5, 3, 2, 10);
	AddAnim("起",0,5,4,10);
	return true;
}


