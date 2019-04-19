#include <memory>
#include "DxLib.h"
#include "VECTOR2.h"
#include "SceneTask.h"
#include "TitleScene.h"
#include "FontMng.h"
#include "ImageMng.h"
#include "GameScene.h"


constexpr int CursorDefPosX = 275;		// ¶°¿Ù‚ÌÃÞÌ«ÙÄÀ•W
constexpr int CursorDefPosY = 325;
constexpr int SelectPos = 415;	// ‘I‘ðŽˆ‚ÌÀ•W
constexpr int Cursormove = 45;	// ¶°¿Ù‚ÌˆÚ“®—Ê

TitleScene::TitleScene()
{
	CursorPos.x = CursorDefPosX;
	CursorPos.y = CursorDefPosY;
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
	ScreenFlip();


	if (key[KEY_INPUT_S] && !keyOld[KEY_INPUT_S])
	{
		if (CursorPos.y >= SelectPos)
		{
			CursorPos.y = CursorDefPosY;
		}
		else
		{
			CursorPos.y += Cursormove;
		}

	}

	if (key[KEY_INPUT_W] && !keyOld[KEY_INPUT_W])
	{
		if (CursorPos.y <= CursorDefPosY)
		{
			CursorPos.y = SelectPos;
		}
		else
		{
			CursorPos.y -= Cursormove;
		}

	}
	if (key[KEY_INPUT_SPACE])
	{
		return std::make_unique<GameScene>();
	}
	return ub;
}
