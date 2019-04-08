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
	VECTOR2 GetBoardActivSize(void);
private:
	RECT StringPos;		// 文字（1プレイ用）座標
	RECT StringPos2;		// 文字（2プレイ用）座標
	int Flash;			// 文字点滅
	int ShadowOffset;	// 文字に影をつける
};

