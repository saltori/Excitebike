#include "SceneTask.h"
#include "DxLib.h"
#include "GameBoard.h"
#include"ImageMng.h"
#include "Player.h"
#include "PieceTray.h"
#include "TitleScene.h"
#include "OPRT_state.h"

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
	Sysmouse = std::make_shared<MouseCtl>();
	Sysmouse->SetOPRT(OPRT_TYPE::MAN);
	return true;
}

void SceneTask::GameRun(void)
{
	activScene = std::make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// マウスを表示状態にする
		//SetMouseDispFlag(FALSE);
		Sysmouse->UpDate();
		//Mouse->UpDate(OPRT_TYPE::CPU);
		activScene = activScene->Update(std::move(activScene),Sysmouse);
	}
}



VECTOR2 SceneTask::GetScreenSize(void)
{
	return VECTOR2(SCREEN_SIZE_X,SCREEN_SIZE_Y);
}

VECTOR2 SceneTask::GetAvtiveBoardSize(void)
{
	if (activScene)
	{
		return activScene->GetBoardActivSize();
	} 
	return VECTOR2(0, 0);
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

