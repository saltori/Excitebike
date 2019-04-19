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
	void GameRun(void);	// Ç±ÇÃíÜÇ≈πﬁ∞—ÇÃŸ∞Ãﬂ
	VECTOR2 GetScreenSize(void);
private:
	struct GameTaskDeleter // ä÷êîµÃﬁºﬁ™∏ƒ
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
	uniqueBase activScene;
	ArrayTime timePoint;
};