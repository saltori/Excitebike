#include "GameScene.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "MapCtl.h"

#define BACKCOLOR (0x9ACD32)	// ”wŒiF


GameScene::GameScene()
{
	MovePos = 0;
	playerList.clear();
	Init();
}


GameScene::~GameScene()
{
}

void GameScene::Init(void)
{

	MakePlayer(VECTOR2(100, 340));
	player = playerList.begin();
	(*player)->Init("image/rider.png", { 24,24}, { 6,6 }, { 1,0});
	camera = std::make_unique<Camera>();
	camera->SetTarget(*player);
	camera->SetPos(VECTOR2(400,200));
	MovePos = -(*player)->GetplayerSpeed();
	(*player)->SetAnim("Ž~");
	
}

uniqueBase GameScene::Update(uniqueBase ub)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);
	const int roadOffset = 1010;	// 2–‡–Ú•\Ž¦‚ÌÛ‚ÌµÌ¾¯Ä
	const int wallOffset = 1150;	// •Ç‚ÌµÌ¾¯Ä
	ClsDrawScreen();
	DrawBox(0, 0, lpSceneTask.GetScreenSize().x, lpSceneTask.GetScreenSize().y, BACKCOLOR, true);

	lpMapCtl.MapDraw();

	(*player)->Draw();
	camera->Update();
	(*player)->SetMove();
	if (key[KEY_INPUT_D])
	{
		
		if((*player)->GetPos().x >= lpSceneTask.GetScreenSize().x / 2)
		{
		lpMapCtl.AddRoadpos({ MovePos,0 });
		lpMapCtl.AddWallpos({ MovePos,0 });
		}
		
	}
	camera->Draw();

	ScreenFlip();
	return ub;
}

const VECTOR2 & GameScene::GetDrawOffset(void)
{
	return -(camera->GetPos() - lpSceneTask.GetScreenSize() / 2);
}

void GameScene::MakePlayer(VECTOR2 vec)
{
	playerList.push_back(std::make_shared<Player>(vec));
}
