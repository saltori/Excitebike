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
	VECTOR2 CursorPos;	// �J�[�\���̍��W
	int Flash;			// �����_��
	int ShadowOffset;	// �����ɉe������
};

