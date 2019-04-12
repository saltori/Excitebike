#include "MapCtl.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "Player.h"

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

	DrawGraph(roadPos.x, roadPos.y, IMAGE_ID("image/road.png")[0], true);
	DrawGraph(roadPos.x + 1009, roadPos.y, IMAGE_ID("image/road.png")[0], true);

	DrawGraph(WallPos.x, WallPos.y, IMAGE_ID("image/wall.png")[0], true);
	DrawGraph(WallPos.x + Walloffset, WallPos.y, IMAGE_ID("image/wall.png")[0], true);
	Update();
}

void MapCtl::Update(void)
{
	if (roadPos.x <= (-RoadOffset + BackDefPosX))
	{
		roadPos.x = BackDefPosX;
	}
	if (WallPos.x <= (-Walloffset + BackDefPosX))
	{
		WallPos.x = BackDefPosX;
	}
}

void MapCtl::AddWallpos(VECTOR2 vec)
{
	WallPos -= vec;
}

void MapCtl::AddRoadpos(VECTOR2 vec)
{
	roadPos -= vec;
}


MapCtl::MapCtl():RoadOffset(1009),Walloffset(1150)
{
	roadPos = { BackDefPosX,RoadPosY };
	WallPos = { BackDefPosX ,BackWallPosY };
}


MapCtl::~MapCtl()
{
}
