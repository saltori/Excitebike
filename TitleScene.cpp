#include <memory>
#include "DxLib.h"
#include "SceneTask.h"
#include "TitleScene.h"
#include "ImageMng.h"
#include "GameScene.h"

#define CURSOR_DEF_POS_X (275)
#define CURSOR_DEF_POS_Y (325)


TitleScene::TitleScene()
{
	CursorPos.x = CURSOR_DEF_POS_X;
	CursorPos.y = CURSOR_DEF_POS_Y;
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init(void)
{
}

uniqueBase TitleScene::Update(uniqueBase ub)
{
	memcpy(keyOld, key, sizeof(keyOld));
	GetHitKeyStateAll(key);
	Flash++;
	ClsDrawScreen();
	DrawRotaGraph(400, 300, 1.8, 0, IMAGE_ID("image/title.png")[0], true);
	DrawGraph(CursorPos.x,CursorPos.y, IMAGE_ID("image/selectFlag.png")[0],true);
	if (key[KEY_INPUT_S]&&!keyOld[KEY_INPUT_S])
	{
		if (CursorPos.y >= 415)
		{
			CursorPos.y = CURSOR_DEF_POS_Y;
		}
		else 
		{
			CursorPos.y += 45;
		}
		
	}

	if (key[KEY_INPUT_W] && !keyOld[KEY_INPUT_W])
	{
		if (CursorPos.y <= CURSOR_DEF_POS_Y)
		{
			CursorPos.y = 415;
		}
		else
		{
			CursorPos.y -= 45;
		}

	}

	if (key[KEY_INPUT_SPACE])
	{
		return std::make_unique<GameScene>();
	}
	ScreenFlip();
	return ub;
}
