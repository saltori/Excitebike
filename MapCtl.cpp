#include "MapCtl.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "Player.h"

constexpr int ViewAreaCntX = 800;
constexpr int ViewAreaCntY = 600;
constexpr int GameAreaCntX = ViewAreaCntX * 5;
constexpr int GameAreaCntY = 600;

constexpr int BackDefPosX	= -10;								// 背景(1枚目)のX座標
constexpr int BackWallPosY	= -50;								// 壁のY座標
constexpr int RoadPosY		= 270;								// 道のY座標


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
	DrawFormatString(100,100,0x000000,"posX : %d",roadPos.x);
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
}


MapCtl::MapCtl():RoadOffset(1009),Walloffset(1150)
{
	roadPos = { BackDefPosX,RoadPosY };
	WallPos = { BackDefPosX ,BackWallPosY };
	roadPos2 = { roadPos.x + RoadOffset,RoadPosY };
}


MapCtl::~MapCtl()
{
}
