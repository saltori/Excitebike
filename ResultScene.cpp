#include "ResultScene.h"
#include "DxLib.h"
#include "ImageMng.h"
#include "SceneTask.h"
#include "FontMng.h"
constexpr int Backcolor  = 0x0000ff;	// îwåiêF
ResultScene::ResultScene()
{
	lpFontMng.FontInit();
}


ResultScene::~ResultScene()
{
}

void ResultScene::Init(void)
{
}

uniqueBase ResultScene::Update(uniqueBase ub)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);

	ClsDrawScreen();
	DrawBox(0,0,lpSceneTask.GetScreenSize().x, lpSceneTask.GetScreenSize().y, Backcolor,true);
	DrawRotaGraph(lpSceneTask.GetScreenSize().x/2, lpSceneTask.GetScreenSize().y/3*2,0.6,0, IMAGE_ID("image/Frame.png")[0],true);
	lpFontMng.FontDraw("BEST TIME", { 200,300 }, { 17,0 }, false);

	ScreenFlip();

	return ub;

}
