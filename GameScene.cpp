#include "GameScene.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "MapCtl.h"
#include "FontMng.h"

class VECTOR2;
constexpr int Backcolor = 0x9ACD32;	// �w�i�F

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
	camera = std::make_unique<Camera>();
	camera->SetTarget(*player);
	camera->SetPos(VECTOR2(400,200));
	(*player)->SetAnim("�~");
	
	
}

uniqueBase GameScene::Update(uniqueBase ub)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);
	const int roadOffset = 1010;	// 2���ڕ\���̍ۂ̵̾��
	const int wallOffset = 1150;	// �ǂ̵̾��
	ClsDrawScreen();
	DrawBox(0, 0, lpSceneTask.GetScreenSize().x, lpSceneTask.GetScreenSize().y, Backcolor, true);

	lpMapCtl.MapDraw();
	
	(*player)->Draw();
	camera->Update();
	(*player)->SetMove();
	
	ScreenFlip();
	return ub;
}

const VECTOR2 & GameScene::GetDrawOffset(void)
{
	return -(camera->GetPos() - lpSceneTask.GetScreenSize() / 2);
}

void GameScene::MakePlayer(FVECTOR2 vec)
{
	playerList.push_back(std::make_shared<Player>(vec));
}
