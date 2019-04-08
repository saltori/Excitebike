#include <memory>
#include "DxLib.h"
#include "SceneTask.h"
#include "TitleScene.h"
#include "ImageMng.h"

TitleScene::TitleScene()
{
	Flash = 0;
	SetFontSize(30);
	StringPos.top = 300;
	StringPos.bottom = 400;
	StringPos.right = StringPos.top + 180;
	StringPos.left = StringPos.bottom + 30;

	StringPos2.top = StringPos.top;
	StringPos2.bottom = 440;
	StringPos2.right = StringPos2.top + 180;
	StringPos2.left = StringPos2.bottom + 30;
	ShadowOffset = 2;
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init(void)
{
}

uniqueBase TitleScene::Update(uniqueBase ub)
{
	Flash++;
	ClsDrawScreen();
	DrawRotaGraph(400, 300, 1.8, 0, IMAGE_ID("image/title.png")[0], true);

	ScreenFlip();
	return ub;
}

VECTOR2 TitleScene::GetBoardActivSize(void)
{
	return VECTOR2(0,0);
}
