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


Player::Player(FVECTOR2 pos)
{
	this->pos = pos;
	speed = PlayerDefSpeed;
	state = PL_STATE::RUN;
	engineBox.top		= 350;
	engineBox.bottom	= 580;
	engineBox.right		= DefaultEngine;
	engineBox.left		= 520;
	OHValue				= 0;
	OHflag				= false;
	engineFlash			= 0;
	animCntAddflg		= true;
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

	if (OHflag)
	{
		engineFlash++;
		if (engineFlash / 10 % 2)
		{
			DrawBox(engineBox.top, engineBox.left, engineBox.right + OHValue, engineBox.bottom, 0xFF0000, true);
		}

	}
	else 
	{
		DrawBox(engineBox.top, engineBox.left, engineBox.right + OHValue, engineBox.bottom, 0xFF0000, true);
	}

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
	if(OHflag)
	{
		lpFontMng.FontDraw({ 330,200, }, { 18,0 }, true);
		//OHValue -= 0.01f;
		if (key[KEY_INPUT_K])
		{
			OHValue = 0.0f;
		}
		if (OHValue <= 0)
		{
			OHflag = false;
		}
		if (pos.y >= 320)
		{
			pos.y--;
		}
	}
	else
	{
		if (pos.y >= GroundPos)
		{
			state = PL_STATE::RUN;
		}
		if (state == PL_STATE::RUN)
		{
			if (OHValue != 0)
			{
				OHValue -= 0.3f;
			}
			if ((engineBox.right + OHValue) >= EngineLimiter)
			{
				OHflag = true;
				lpFontMng.FontSet("OVER HEAT");
			}

			if (key[KEY_INPUT_A])
			{
				if ((key[KEY_INPUT_A] && !keyOld[KEY_INPUT_A]))
				{
					animCntAddflg = true;
					SetAnim("走");
				}
				lpMapCtl.AddRoadpos({ speed / 2,0 });
				lpMapCtl.AddWallpos({ speed / 2,0 });

				if ((engineBox.right + OHValue) <= EngineLimiter - 20)
				{
					OHValue += 0.5f;
				}
			}
			else if (key[KEY_INPUT_S])
			{
				if ((key[KEY_INPUT_S] && !keyOld[KEY_INPUT_S]))
				{
					animCntAddflg = true;
					SetAnim("走");
				}
				lpMapCtl.AddRoadpos({ speed,0 });
				lpMapCtl.AddWallpos({ speed,0 });
				if ((engineBox.right + OHValue) <= EngineLimiter)
				{
					OHValue += 0.7f;
				}
			}
			else {}
			if (key[KEY_INPUT_DOWN] && keyOld[KEY_INPUT_DOWN])
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

			if (key[KEY_INPUT_LEFT] && !keyOld[KEY_INPUT_LEFT])
			{
				SetAnim("ウィリー");
				state = PL_STATE::WHEELIE;
			}
		}
		if (state == PL_STATE::WHEELIE)
		{
			if (animCnt == 30)
			{
				animCntAddflg = false;
			}
		}
		if (state == PL_STATE::JUMP)
		{
			pos.y += 0.2f;
			if (pos.y <= GroundPos)
			{
				state = PL_STATE::RUN;
			}
			if (key[KEY_INPUT_LEFT] && !keyOld[KEY_INPUT_LEFT])
			{
				SetAnim("ウィリー");
				animCnt = 0;
				animCntAddflg = true;
			}
			if (key[KEY_INPUT_RIGHT] && !keyOld[KEY_INPUT_RIGHT])
			{
				animCnt = 0;
				animCntAddflg = true;
				SetAnim("着地");
			}
			if (animCnt == 25)
			{
				animCntAddflg = false;
			}

		}

	}

	if (lpMapCtl.HitCheck(pos))
	{
		state = PL_STATE::JUMP;
		pos.y -= 200;

	}

	if (animCntAddflg)
	{
		animCnt++;
	}
}

const VECTOR2 & Player::GetPos(void)
{
	return { static_cast<int>(pos.x) ,static_cast<int>(pos.y) };
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
	AddAnim("ウィリー", 0, 1, 5, 10);
	AddAnim("着地", 0, 2, 3, 10);
	AddAnim("逆", 0, 3, 4, 10);
	AddAnim("足", 5, 3, 2, 10);
	AddAnim("起",0,5,4,10);
	return true;
}


