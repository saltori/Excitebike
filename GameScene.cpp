#include "GameScene.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"

#define BACKCOLOR (0x9ACD32) // 背景色
#define BACKWALL_POS_X (0)	// 壁(1枚目)のX座標
#define BACKWALL_POS_Y (-50)	// 壁のY座標
#define ROAD_POS_X (lpSceneTask.GetScreenSize().x/2)	// 道のX座標
#define ROAD_POS_Y (270)								// 道のY座標

GameScene::GameScene()
{
	MovePos = 0;
}


GameScene::~GameScene()
{
}

void GameScene::Init(void)
{
}

uniqueBase GameScene::Update(uniqueBase ub)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);
	const int roadOffset = 1010;	// 2枚目表示の際のオフセット
	const int wallOffset = 1150;	// 壁のオフセット
	ClsDrawScreen();
	DrawBox(0, 0, lpSceneTask.GetScreenSize().x, lpSceneTask.GetScreenSize().y, BACKCOLOR, true);
	DrawRotaGraph(lpSceneTask.GetScreenSize().x / 2, 547, 1.7, 0, IMAGE_ID("image/engine.png")[0], true);
	DrawGraph(-10 + MovePos, ROAD_POS_Y, IMAGE_ID("image/road.png")[0], true);
	DrawGraph(-10 + roadOffset + MovePos, ROAD_POS_Y, IMAGE_ID("image/road.png")[0], true);
	DrawGraph(BACKWALL_POS_X + MovePos, BACKWALL_POS_Y,IMAGE_ID("image/wall.png")[0], true);
	DrawGraph(BACKWALL_POS_X + wallOffset + MovePos, BACKWALL_POS_Y, IMAGE_ID("image/wall.png")[0], true);

	if (key[KEY_INPUT_D])
	{
		MovePos -= 10;
	}

	if (MovePos <= -wallOffset)
	{
		MovePos = 0;
	}

	ScreenFlip();
	return ub;
}
