#pragma once
#include "BaseScene.h"

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	void Init(void);
	uniqueBase Update(uniqueBase ub);
private:
	VECTOR2 CursorPos;	// カーソルの座標
	int Flash;			// 文字点滅
	int ShadowOffset;	// 文字に影をつける
};

