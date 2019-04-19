#include "MapCtl.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "Player.h"
#include  "SlopeA.h"
#include "SlopeB.h"
#include "Axcel.h"
#include "Swamp.h"
#include "Finish.h"

constexpr int ViewAreaCntX = 800;
constexpr int ViewAreaCntY = 600;
constexpr int GameAreaCntX = ViewAreaCntX * 5;
constexpr int GameAreaCntY = 600;

constexpr float BackDefPosX		= -10.0f;	// îwåi(1ñáñ⁄)ÇÃXç¿ïW
constexpr float BackWallPosY	= -50.0f;	// ï«ÇÃYç¿ïW
constexpr float RoadPosY		= 270.0f;	// ìπÇÃYç¿ïW



std::unique_ptr<MapCtl, MapCtl::MapCtlDeleter> MapCtl::s_Instance(new MapCtl());

VECTOR2 MapCtl::GetAreaSize(void)
{
	return VECTOR2(GameAreaCntX,GameAreaCntY);
}

VECTOR2 MapCtl::GetViewSize(void)
{
	return  VECTOR2(ViewAreaCntX, ViewAreaCntY);
}

void MapCtl::MapDraw(void)
{


	for (int i = 0; i < 10; i++)
	{
		DrawGraph(roadPos.x + RoadOffset * i, roadPos.y, IMAGE_ID("image/road.png")[0], true);
		DrawGraph(WallPos.x + Walloffset * i, WallPos.y, IMAGE_ID("image/wall.png")[0], true);
	}

	for (auto tmp = partvec.begin();tmp != partvec.end();tmp++)
	{
		(**tmp).Update();
	}
	//DrawFormatString(20, 40, 0x000000, "roadPosX:%f", roadPos.x);

	Update();
}

void MapCtl::Update(void)
{
	Measurement();
	TimeCon();
}

void MapCtl::AddWallpos(FVECTOR2 vec)
{
	WallPos -= vec;
}

void MapCtl::AddRoadpos(FVECTOR2 vec)
{
	roadPos -= vec;
	for (auto tmp = partvec.begin(); tmp != partvec.end(); ++tmp)
	{
		(**tmp).AddPartPos(-vec.x);
	}
}

bool MapCtl:: Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue)
{
	bool rtnFlag = false;
	for (auto tmp = partvec.begin(); tmp != partvec.end(); ++tmp)
	{
		rtnFlag = rtnFlag|(**tmp).Collision(pos, speed, state, OHValue);
	}
	return rtnFlag;
}

void MapCtl::HitEffect(float & speed, PL_STATE &state, float &OHValue)
{
	for (auto tmp = partvec.begin(); tmp != partvec.end(); ++tmp)
	{
		(**tmp).HitEffect(speed,state,OHValue);
	}
}

void MapCtl::SetGoalFlag(bool flg)
{
	GoalFlag = flg;
}

bool MapCtl::GetGoalFlag(void)
{
	return GoalFlag;
}

void MapCtl::StartTime(void)
{
	TimeFlag = true;
}

RecordTime MapCtl::GetRecordTime(void)
{
	return recordTime;
}

void MapCtl::SetState(Track_Parts state, int PosX)
{
	switch (state)
	{
	case Track_Parts::SLOPE_A:
		partvec.emplace_back(std::make_unique<SlopeA>(PosX));
		break;
	case Track_Parts::SLOPE_B:
		partvec.emplace_back(std::make_unique<SlopeB>(PosX));
		break;
	case Track_Parts::SLOPE_C:
		break;
	case Track_Parts::SLOPE_D:
		break;
	case Track_Parts::SLOPE_E:
		break;
	case Track_Parts::SLOPE_F:
		break;
	case Track_Parts::SLOPE_G:
		break;
	case Track_Parts::SLOPE_H:
		break;
	case Track_Parts::AXCEL:
		partvec.emplace_back(std::make_unique<Axcel>(PosX));
		break;
	case Track_Parts::FENCE:
		break;
	case Track_Parts::LONG_TURF:
		break;
	case Track_Parts::WIDE_TURF:
		break;
	case Track_Parts::MISHMASH:
		break;
	case Track_Parts::SWAMP:
		partvec.emplace_back(std::make_unique<Swamp>(PosX));
		break;
	case Track_Parts::FNISH:
		partvec.emplace_back(std::make_unique<Finish>(PosX));
		break;
	case Track_Parts::MAX:
		break;
	default:
		break;
	}
}

void MapCtl::Measurement(void)
{
	if (TimeFlag)
	{
		recordTime.Minutes++;
	}
}

void MapCtl::TimeCon(void)
{
	recordTime.Second = (recordTime.Minutes % 3600) / 60;
	recordTime.Minutes = recordTime.Minutes % 60;
}

void MapCtl::SetStage(void)
{
	SetState(Track_Parts::SLOPE_A,700);
	SetState(Track_Parts::SLOPE_B, 1000);
	SetState(Track_Parts::SWAMP, 1200);
	SetState(Track_Parts::AXCEL, 1400);
	SetState(Track_Parts::SLOPE_A, 1600);
	SetState(Track_Parts::SLOPE_A, 1700);
	SetState(Track_Parts::SLOPE_A, 1800);
	SetState(Track_Parts::SLOPE_A, 1900);
	SetState(Track_Parts::AXCEL, 2200);
	SetState(Track_Parts::FNISH, 3000);

}


MapCtl::MapCtl():RoadOffset(1009),Walloffset(1150)
{
	roadPos = { BackDefPosX,RoadPosY };
	WallPos = { BackDefPosX ,BackWallPosY };
	roadPos2 = { roadPos.x + RoadOffset,RoadPosY };
	SetStage();
	GoalFlag = false;
	TimeFlag = false;
}


MapCtl::~MapCtl()
{
}
