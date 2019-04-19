#include "Player.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "MapCtl.h"
#include "FontMng.h"
constexpr int PlayerMaxSpeed = 15;
constexpr int DefaultEngine = 350;
constexpr unsigned int EngineLimiter = 466;
constexpr float UpSideGroundPos = 335.0f;	// 地面か空中化の分岐点(上)
constexpr float DownSideGroundPos = 430.0f;	// 地面か空中化の分岐点(下)

constexpr int PlayerChipOffsetX = 1;	// 描画ﾁｯﾌﾟのｵﾌｾｯﾄ
constexpr int PlayerChipOffsetY = 0;	// 描画ﾁｯﾌﾟのｵﾌｾｯﾄ

constexpr float AcceleA = 0.3f;
constexpr float AcceleB = 0.5f;
Player::Player():Gravity(2.2f)
{

}


Player::Player(FVECTOR2 pos):Gravity(3.0f)
{
	this->pos = pos;
	speed = 0;
	state = PL_STATE::RUN;
	engineBox.top		= 350;
	engineBox.bottom	= 580;
	engineBox.right		= DefaultEngine;
	engineBox.left		= 520;
	OHValue				= 0;
	OHflag				= false;
	Flash			= 0;
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
	lpMapCtl.StartTime();
}

void Player::Draw(void)
{
	if (OHflag)
	{
		Flash++;
		if (Flash / 10 % 2)
		{
			DrawBox(engineBox.top, engineBox.left, engineBox.right + OHValue, engineBox.bottom, 0xFF0000, true);
		}

	}
	else 
	{
		DrawBox(engineBox.top, engineBox.left, engineBox.right + OHValue, engineBox.bottom, 0xFF0000, true);
	}

	DrawRotaGraph(lpSceneTask.GetScreenSize().x / 2, 547, 1.7, 0, IMAGE_ID("image/engine.png")[0], true);
	//DrawFormatString(100,100,0x00000,":%d分",lpMapCtl.GetRecordTime().Minutes);
	//DrawFormatString(100, 130, 0x00000, ":%d秒", lpMapCtl.GetRecordTime().Second);
	//DrawFormatString(100, 150, 0x00000, ":%dﾐﾘ", lpMapCtl.GetRecordTime().Milli);
	int id = 0;

	if (!(animTable.find(animName) == animTable.end()))
	{
		id = animTable[animName][static_cast<int>(ANIM_TBL::START_ID)] + (animCnt / animTable[animName][static_cast<int>(ANIM_TBL::INV)]%animTable[animName][static_cast<int>(ANIM_TBL::FRAME)]);
	}

	DrawRotaGraph(pos.x, pos.y,2,0, IMAGE_ID(imageName)[id], true);
	//DebugDraw();	// ﾃﾞﾊﾞｯｸ用

}

void Player::SetMove(void)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);
	if(OHflag)
	{
		lpFontMng.FontDraw("OVER HEAT", { 330,200, }, { 18,0 }, true);
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
		if (pos.y >= PlayerGround && pos.y <= DownSideGroundPos)// pos.y >= UpSideGroundPos &&
		{
			
			if (state == PL_STATE::NOSEMANUAL)
			{
				state = PL_STATE::JUMP;
				v.y = -speed * 0.8;
			}
			else if (state == PL_STATE::JUMP)
			{
				state = PL_STATE::RUN;
			}
			else if(state == PL_STATE::FINISH)
			{
				SetAnim("ウィリー");
			}
			else
			{}
		}
		if (state == PL_STATE::RUN||state == PL_STATE::WHEELIE)
		{
			speed -= 0.2f;
			if (speed <= 0.0f)
			{
				speed = 0.00f;
			}
			lpMapCtl.AddRoadpos({ speed,0 });
			lpMapCtl.AddWallpos({ speed,0 });
			if (OHValue != 0)
			{
				OHValue -= 0.3f;
			}
			if ((engineBox.right + OHValue) >= EngineLimiter)
			{
				OHflag = true;
				SetAnim("止");
			}

			if (key[KEY_INPUT_A])
			{
				if (speed <= PlayerMaxSpeed)
				{
					speed += AcceleA;
				}
				if ((key[KEY_INPUT_A] && !keyOld[KEY_INPUT_A]))
				{
					animCntAddflg = true;
					SetAnim("走");
				}
				if ((engineBox.right + OHValue) <= EngineLimiter - 20)
				{
					OHValue += 0.5f;
				}
			}
			else if (key[KEY_INPUT_S])
			{
				if (speed <= PlayerMaxSpeed)
				{
					speed += AcceleB;
				}
				if ((key[KEY_INPUT_S] && !keyOld[KEY_INPUT_S]))
				{
					animCntAddflg = true;
					SetAnim("走");
				}
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
				if (pos.y >= DownSideGroundPos)
				{
					pos.y = DownSideGroundPos;
				}
			}
			if (key[KEY_INPUT_UP] && !keyOld[KEY_INPUT_UP])
			{
				SetAnim("左");
			}
			if (key[KEY_INPUT_UP])
			{
				pos.y -= speed / 2;
				if(pos.y <= UpSideGroundPos)
				{
					pos.y = UpSideGroundPos;
				}
			}

			if (key[KEY_INPUT_LEFT])
			{
				if (state != PL_STATE::WHEELIE)
				{
					SetAnim("ウィリー");
					state = PL_STATE::WHEELIE;
					animCntAddflg = false;
				}
				if (animCnt < 14)
				{
					animCnt++;
				}

			}
			if (state == PL_STATE::WHEELIE)
			{
				if (!key[KEY_INPUT_LEFT])
				{
					if (animCnt <= 0)
					{
						animCnt = 0;
						state = PL_STATE::RUN;
					}
					animCnt--;
				}
			}
		}
		if (state == PL_STATE::JUMP ||state == PL_STATE::NOSEMANUAL)
		{


			Fall();

			if (key[KEY_INPUT_LEFT] && !keyOld[KEY_INPUT_LEFT])
			{
				SetAnim("ウィリー");
				animCntAddflg = true;
			}
			if (key[KEY_INPUT_LEFT])
			{
				animCnt++;
			}
			if (key[KEY_INPUT_RIGHT] && !keyOld[KEY_INPUT_RIGHT])
			{
				animCntAddflg = true;
				state = PL_STATE::NOSEMANUAL;
				SetAnim("着地");
			}
			if (animCnt == 20)
			{
				animCntAddflg = false;
			}
		}
	}

	if (lpMapCtl.Collision(pos,speed,state,OHValue))
	{
		if (state == PL_STATE::JUMP)
		{
			SetAnim("ジャンプ");
			v.y = -speed*1.2f;
			PlayerGround = pos.y;
			pos.y -= speed;
		}
		if (state == PL_STATE::FINISH)
		{
			SetAnim("ジャンプ");
			v.y = -speed * 1.2f;
			PlayerGround = pos.y;
			pos.y -= speed;
			animCntAddflg = false;

		}
	}
	if (state == PL_STATE::FINISH)
	{
		if (animCnt < 14)
		{
			animCnt++;
		}
		if (speed > 0)
		{
			speed -= 0.1f;
			Fall();
		}
		else
		{
			speed = 0;
			lpMapCtl.SetGoalFlag(true);
		}
		if (pos.y > PlayerGround)
		{
			pos.y = PlayerGround;
		}
	}
	if (pos.y <= 0)
	{
		pos.y = lpSceneTask.GetScreenSize().y;
	}
	if (pos.x >= lpSceneTask.GetScreenSize().x)
	{
		pos.x = 0;
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

PL_STATE Player::GetState(void)
{
	return state;
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
	AddAnim("ウィリー", 0, 1, 6, 3);
	AddAnim("ジャンプ", 0, 1, 3, 7);
	AddAnim("着地", 0, 2, 3, 10);
	AddAnim("逆", 0, 3, 4, 10);
	AddAnim("足", 5, 3, 2, 10);
	AddAnim("起",0,5,4,10);
	AddAnim("ゴール", 4, 1, 1, 1);
	return true;
}

void Player::Fall(void)
{
	DrawOval(pos.x, PlayerGround + PlayerDivSize, 7, 5, 0x000000, true);
	pos.y += v.y;
	v.y++;
	pos.y += Gravity;
	lpMapCtl.AddRoadpos({ speed,0 });
	lpMapCtl.AddWallpos({ speed,0 });
}

void Player::DebugDraw(void)
{
	DrawFormatString(20,20, 0x000000, "posY:%f",pos.y);
	DrawFormatString(20, 50, 0x000000, "speed:%f", speed);
	DrawFormatString(20, 7, 0x000000, "animCnt:%d", animCnt);
}


