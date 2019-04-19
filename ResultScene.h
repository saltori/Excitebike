#pragma once
#include "BaseScene.h"
class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	void Init(void);
	uniqueBase Update(uniqueBase ub);
};

