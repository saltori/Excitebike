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
	RECT StringPos;		// �����i1�v���C�p�j���W
	RECT StringPos2;		// �����i2�v���C�p�j���W
	int Flash;			// �����_��
	int ShadowOffset;	// �����ɉe������
};

