#pragma once
#include <memory>
//#include "SceneTask.h"

enum SCENE_ST {
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_TASK,
	SCENE_MAX,
};

class BaseScene;
using uniqueBase = std::unique_ptr<BaseScene>;
class VECTOR2;
class BaseScene
{
public:
	virtual ~BaseScene();
	virtual void Init(void) = 0;
	virtual uniqueBase Update(uniqueBase ub) = 0;
	virtual VECTOR2 GetBoardActivSize(void) = 0;
};

