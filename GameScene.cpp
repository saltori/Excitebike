#include "GameScene.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "MapCtl.h"
#include "FontMng.h"
#include"ResultScene.h"

class VECTOR2;

constexpr int Backcolor = 0x9ACD32;			// ”wŒiF
GameScene::GameScene()
{
	playerList.clear();
	Init();
}


GameScene::~GameScene()
{
}

void GameScene::Init(void)
{
	MakePlayer(FVECTOR2(100.0f, 340.0f));
	player = playerList.begin();
	(*player)->Init("image/rider.png", { PlayerDivSize,PlayerDivSize }, { PlayerDivCnt,PlayerDivCnt }, { 1,0});
	FontMng::GetInstance().FontInit();
	(*player)->SetAnim("Ž~");
	lpSceneTask.StartPrgTime();
	FlashBox = {0,0,lpSceneTask.GetScreenSize().x,lpSceneTask.GetScreenSize().y/4};
}

uniqueBase GameScene::Update(uniqueBase ub)
{
	ClsDrawScreen();
	DrawBox(0, 0, lpSceneTask.GetScreenSize().x, lpSceneTask.GetScreenSize().y, Backcolor, true);
	if ((*player)->GetState() == PL_STATE::FINISH)
	{
		Flash++;
		if (Flash / 10 % 2)
		{
			DrawBox(FlashBox.top, FlashBox.left, FlashBox.right, FlashBox.bottom, 0xFF0000, true);
		}
	}

	lpMapCtl.MapDraw();
	(*player)->Draw();
	ScreenFlip();

	(*player)->SetMove();
	lpMapCtl.Update();
	if (lpMapCtl.GetGoalFlag())
	{
		lpMapCtl.SetGoalFlag(false);
		return std::make_unique<ResultScene>();
	}
	return ub;
}

void GameScene::MakePlayer(FVECTOR2 vec)
{
	playerList.push_back(std::make_shared<Player>(vec));
}
