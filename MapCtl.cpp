#include "MapCtl.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "Player.h"
#include  "SlopeA.h"

constexpr int ViewAreaCntX = 800;
constexpr int ViewAreaCntY = 600;
constexpr int GameAreaCntX = ViewAreaCntX * 5;
constexpr int GameAreaCntY = 600;

constexpr int BackDefPosX	= -10;								// îwåi(1ñáñ⁄)ÇÃXç¿ïW
constexpr int BackWallPosY	= -50;								// ï«ÇÃYç¿ïW
constexpr int RoadPosY		= 270;								// ìπÇÃYç¿ïW


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
	square hitbox;
	for (int i = 0; i < 10; i++)
	{
		DrawGraph(roadPos.x + RoadOffset * i, roadPos.y, IMAGE_ID("image/road.png")[0], true);
		DrawGraph(WallPos.x + Walloffset * i, WallPos.y, IMAGE_ID("image/wall.png")[0], true);
	}
	DrawFormatString(100,100,0x000000,"posX : %d",roadPos.x);

	for (auto tmp = partvec.begin();tmp != partvec.end();tmp++)
	{
		(**tmp).Update();
	}

	Update();
}

void MapCtl::Update(void)
{
}

void MapCtl::AddWallpos(VECTOR2 vec)
{
	WallPos -= vec;
}

void MapCtl::AddRoadpos(VECTOR2 vec)
{
	roadPos -= vec;
	for (auto tmp = partvec.begin(); tmp != partvec.end(); tmp++)
	{
		(**tmp).AddPartPos(-vec.x);
	}
}

bool MapCtl::HitCheck(FVECTOR2 pos)
{
	bool rtnFlag = false;
	for (auto tmp = partvec.begin(); tmp != partvec.end(); tmp++)
	{
		rtnFlag = rtnFlag|(**tmp).HitCheck(pos);
	}
	return rtnFlag;
}

void MapCtl::SetState(Track_Parts state, VECTOR2 pos)
{
	switch (state)
	{
	case Track_Parts::SLOPE_A:
		partvec.push_back(std::make_unique<SlopeA>(pos));
		break;
	case Track_Parts::SLOPE_B:
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
		break;
	case Track_Parts::MAX:
		break;
	default:
		break;
	}
}


MapCtl::MapCtl():RoadOffset(1009),Walloffset(1150)
{
	roadPos = { BackDefPosX,RoadPosY };
	WallPos = { BackDefPosX ,BackWallPosY };
	roadPos2 = { roadPos.x + RoadOffset,RoadPosY };
	SetState(Track_Parts::SLOPE_A, {200,380});
	SetState(Track_Parts::SLOPE_A, { 2000,380 });
}


MapCtl::~MapCtl()
{
}
