#include "SceneTask.h"
#include "DxLib.h"
#include"ImageMng.h"
#include "TitleScene.h"

#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

//SceneTask *SceneTask::s_Instance = nullptr;
//std::once_flag SceneTask::initFlag;
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
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);	// 画面ｻｲｽﾞ設定
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
		// マウスを表示状態にする
		//SetMouseDispFlag(FALSE);
		//Mouse->UpDate(OPRT_TYPE::CPU);
		activScene = activScene->Update(std::move(activScene));
	}
}



VECTOR2 SceneTask::GetScreenSize(void)
{
	return VECTOR2(SCREEN_SIZE_X,SCREEN_SIZE_Y);
}

void SceneTask::StartPrgTime()
{
	timePoint[static_cast<int>(TIME_ST::START)] = chrono_clock::now();
}

void SceneTask::EndPrgTime()
{
	timePoint[static_cast<int>(TIME_ST::END)] = chrono_clock::now();
}

__int64 SceneTask::GetPrgTime()
{
	return std::chrono::duration_cast<std::chrono::seconds>(timePoint[static_cast<int>(TIME_ST::END)] - timePoint[static_cast<int>(TIME_ST::START)]).count();
}

