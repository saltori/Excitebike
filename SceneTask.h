#pragma once
#include <mutex>
#include<memory>
#include <list>
#include <array>
#include <chrono>
#include "VECTOR2.h"
#include "BaseScene.h"
#define lpSceneTask (SceneTask::GetInstance())

class TitleScene;
class GameScene;
class ResultScene;

enum class TIME_ST {
	START,
	END,
	MAX
};

using chrono_clock = std::chrono::system_clock;
using timepoint = chrono_clock::time_point;
using ArrayTime = std::array<timepoint, static_cast<size_t>(TIME_ST::MAX)>;

class SceneTask
{
public:
	//static void Destroy(void);
	static SceneTask &GetInstance(void)
	{
		//std::call_once(initFlag,Create);
		return *s_Instance;
	}
	void GameRun(void);	// この中でゲームのループ
	VECTOR2 GetScreenSize(void);
	VECTOR2 GetAvtiveBoardSize(void);
	void StartPrgTime();	// 計測開始	
	void EndPrgTime();		// 終了
	__int64 GetPrgTime();	// 開始から終了
private:
	struct GameTaskDeleter // 関数オブジェクト
	{
		void operator()(SceneTask* gameTask) const
		{
			delete gameTask;
		}
	};
	static std::unique_ptr<SceneTask, GameTaskDeleter> s_Instance;
	SceneTask();
	~SceneTask();
	int (SceneTask::*GtskPtr)(void);
	int Init(void);
	int passCnt;	// 連続で何人パスしたか
	uniqueBase activScene;
	ArrayTime timePoint;
};