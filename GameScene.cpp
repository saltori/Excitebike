#include "GameScene.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"

#define BACKCOLOR (0x9ACD32)	// ”wŒiF
#define BACK_POS_X (-10)		// ”wŒi(1–‡–Ú)‚ÌXÀ•W
#define BACKWALL_POS_Y (-50)	// •Ç‚ÌYÀ•W
#define ROAD_POS_Y (270)								// “¹‚ÌYÀ•W

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
	(*player)->Init("image/cameraman.png", { 20,45  }, { 4,2 }, { 1,0 });
	(*player)->Init("image/rider.png", { 26,32}, { 5,6 }, { 1,0});
	camera = std::make_unique<Camera>();
	camera->SetTarget(*player);
	camera->SetPos(VECTOR2(400,200));
}

uniqueBase GameScene::Update(uniqueBase ub)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);
	const int roadOffset = 1010;	// 2–‡–Ú•\Ž¦‚ÌÛ‚ÌµÌ¾¯Ä
	const int wallOffset = 1150;	// •Ç‚ÌµÌ¾¯Ä
	ClsDrawScreen();
	DrawBox(0, 0, lpSceneTask.GetScreenSize().x, lpSceneTask.GetScreenSize().y, BACKCOLOR, true);
	DrawRotaGraph(lpSceneTask.GetScreenSize().x / 2, 547, 1.7, 0, IMAGE_ID("image/engine.png")[0], true);

	DrawGraph(BACK_POS_X + MovePos, ROAD_POS_Y, IMAGE_ID("image/road.png")[0], true);
	DrawGraph(BACK_POS_X + roadOffset + MovePos, ROAD_POS_Y, IMAGE_ID("image/road.png")[0], true);

	DrawGraph(BACK_POS_X + MovePos, BACKWALL_POS_Y,IMAGE_ID("image/wall.png")[0], true);
	DrawGraph(BACK_POS_X + wallOffset + MovePos, BACKWALL_POS_Y, IMAGE_ID("image/wall.png")[0], true);

	for (auto itr = playerList.begin(); itr != playerList.end(); itr++)
	{
		(*itr)->Draw();
	}
	camera->Update();
	for (auto itr = playerList.begin(); itr != playerList.end(); itr++)
	{
		(*itr)->SetMove();
	}
	if (key[KEY_INPUT_D] && (*player)->GetPos().x >= lpSceneTask.GetScreenSize().x / 2)
	{
		MovePos -= 5;
	}
	if (MovePos <= -1024)
	{
		int i = 0;
	}
	camera->Draw();
	//if (MovePos <= -wallOffset)
	//{
	//	MovePos = 0;
	//}

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
