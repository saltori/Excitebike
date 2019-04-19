#include "SceneTask.h"
#include "DxLib.h"
#include"ImageMng.h"
#include "TitleScene.h"

constexpr int ScreenSizeX = 800;
constexpr int ScreenSizeY = 600;

std::unique_ptr<SceneTask,SceneTask::GameTaskDeleter> SceneTask::s_Instance(new SceneTask());

SceneTask::SceneTask()
{
	Init();
}

SceneTask::~SceneTask()
{
	DxLib_End();
}



int SceneTask::Init(void)
{
	SetWindowText("1701309_川田 栞");
	SetGraphMode(ScreenSizeX, ScreenSizeY, 16);	// 画面ｻｲｽﾞ設定
	ChangeWindowMode(true);				// true:window　false:ﾌﾙｽｸﾘｰﾝ		
	if (DxLib_Init() == -1)
	{
		return -1;	// ＤＸライブラリ初期化処理
	}
	SetDrawScreen(DX_SCREEN_BACK);	// エラーが起きたら直ちに終了
	return true;
}

void SceneTask::GameRun(void)
{
	activScene = std::make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		activScene = activScene->Update(std::move(activScene));
	}
}

VECTOR2 SceneTask::GetScreenSize(void)
{
	return VECTOR2(ScreenSizeX,ScreenSizeY);
}
