#include "MapCtl.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "Player.h"

#define VIEW_AREA_CNT_X (800)
#define VIEW_AREA_CNT_Y (600)
#define GAME_AREA_CNT_X (VIEW_AREA_CNT_X * 5)
#define GAME_AREA_CNT_Y (600)

#define BACK_DEF_POS_X (-10)		// îwåi(1ñáñ⁄)ÇÃXç¿ïW
#define BACKWALL_POS_Y (-50)	// ï«ÇÃYç¿ïW
#define ROAD_POS_Y (270)								// ìπÇÃYç¿ïW


std::unique_ptr<MapCtl, MapCtl::MapCtlDeleter> MapCtl::s_Instance(new MapCtl());

VECTOR2 MapCtl::GetAreaSize(void)
{
	return VECTOR2(GAME_AREA_CNT_X,GAME_AREA_CNT_Y);
}

VECTOR2 MapCtl::GetViewSize(void)
{
	return  VECTOR2(VIEW_AREA_CNT_X, VIEW_AREA_CNT_Y);
}

void MapCtl::MapDraw(void)
{
	DrawRotaGraph(lpSceneTask.GetScreenSize().x / 2, 547, 1.7, 0, IMAGE_ID("image/engine.png")[0], true);

	DrawGraph(roadPos.x, roadPos.y, IMAGE_ID("image/road.png")[0], true);
	DrawGraph(roadPos.x + 1009, roadPos.y, IMAGE_ID("image/road.png")[0], true);

	DrawGraph(WallPos.x, WallPos.y, IMAGE_ID("image/wall.png")[0], true);
	DrawGraph(WallPos.x + Walloffset, WallPos.y, IMAGE_ID("image/wall.png")[0], true);
	Update();
}

void MapCtl::Update(void)
{
	if (roadPos.x <= (-RoadOffset + BACK_DEF_POS_X))
	{
		roadPos.x = BACK_DEF_POS_X;
	}
	if (WallPos.x <= (-Walloffset + BACK_DEF_POS_X))
	{
		WallPos.x = BACK_DEF_POS_X;
	}
}

void MapCtl::AddWallpos(VECTOR2 vec)
{
	WallPos += vec;
}

void MapCtl::AddRoadpos(VECTOR2 vec)
{
	roadPos += vec;
}


MapCtl::MapCtl():RoadOffset(1009),Walloffset(1150)
{
	roadPos = { BACK_DEF_POS_X,ROAD_POS_Y };
	WallPos = { BACK_DEF_POS_X ,BACKWALL_POS_Y };
}


MapCtl::~MapCtl()
{
}
