#pragma once

#include <string>
#include <map>
#include "VECTOR2.h"
#include "FVECTOR2.h"


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

constexpr int PlayerDivSize		= 24;	// ��ڲ԰�̻���
constexpr int PlayerDivCnt		= 6;	// ��ڲ԰�̺ϐ�
constexpr int PlayerChipOffsetX = 1;	// �`�����߂̵̾��
constexpr int PlayerChipOffsetY = 0;	// �`�����߂̵̾��
constexpr float GroundPos		= 200.0f;	// �n�ʂ��󒆉��̕���_

class Player
{
public:
	Player();
	Player(FVECTOR2 pos);
	~Player();
	void Init(std::string filename,VECTOR2 divSize,VECTOR2 divCnt,VECTOR2 chipOffset);	// ��ڲ԰�̕`��
	void Draw(void);
	void SetMove(void);
	const VECTOR2 &GetPos(void);
	const int GetplayerSpeed(void);
	bool SetAnim(std::string animName);
	void AddanimCnt(int aniCnt);

private:
	FVECTOR2 pos;			// ��ڲ԰�̍��W
	PL_STATE state;			// ��ڲ԰�̏��
	ANIM_TBL animTbl;		// ��Ұ���
	char key[256];
	char keyOld[256];
	int speed;				// �޲��̽�߰��
	std::string imageName;
	VECTOR2 divSize;		//// �`�����߂̻���
	VECTOR2 divCnt;		// �`�����ߐ��i�c���j
	VECTOR2 chipOffset; // �`�����߂̃C���[�WID�̵̾��
	std::map<std::string, int[static_cast<int>(ANIM_TBL::MAX)]> animTable;	// ��Ұ��݂�ð���
	std::string animName;	// �I�𒆂̱�Ұ���
	unsigned int animCnt;
	bool AddAnim(std::string animName, int id_x, int id_y, int frame, int inv);
	bool initAnim(void);
	bool OHflag;					// ���ް˰Ă��ǂ������׸�
	square engineBox;				// �ݼ��
	float OHValue;					// ���ް˰�
	int engineFlash;				// �ݼ�݂�_�ł�����p
	bool animCntAddflg;				// ��Ұ��݂�ٰ�ߗp
};

