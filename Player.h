#pragma once

#include <string>
#include "VECTOR2.h"

enum class PL_STATE {
	STOP,		// �~�܂��Ă���
	RUN,		// ���s���
	JUMP,		// �ެ��ߒ�
	WHEELIE,	// ��ذ
	OVERHEAT,	// ���ް˰�
};

enum class ANIM_TBL {
	START_ID,	// �Y����Ұ��݂̕\�����߂̊J�n�ʒu��ID
	FRAME,		// ��Ұ��݂̺ϐ�
	INV,		// �������
	MAX
};

class Player
{
public:
	Player();
	Player(VECTOR2 pos);
	~Player();
	void Draw(std::string filename,VECTOR2 divSize,VECTOR2 divCnt,VECTOR2 chipOffset);	// ��ڲ԰�̕`��
	void SetMove(void);

private:
	VECTOR2 pos;		// ��ڲ԰�̍��W
	PL_STATE state;		// ��ڲ԰�̏��
	ANIM_TBL animTbl;	// ��Ұ���
	char key[256];
	int speed;			// �޲��̽�߰��
};

