#pragma once

#include <string>
#include "VECTOR2.h"

enum class PL_STATE {
	STOP,		// 止まっている
	RUN,		// 走行状態
	JUMP,		// ｼﾞｬﾝﾌﾟ中
	WHEELIE,	// ｳｨﾘｰ
	OVERHEAT,	// ｵｰﾊﾞｰﾋｰﾄ
};

enum class ANIM_TBL {
	START_ID,	// 該当ｱﾆﾒｰｼｮﾝの表示ﾁｯﾌﾟの開始位置のID
	FRAME,		// ｱﾆﾒｰｼｮﾝのｺﾏ数
	INV,		// ｲﾝﾀｰﾊﾞﾙ
	MAX
};

class Player
{
public:
	Player();
	Player(VECTOR2 pos);
	~Player();
	void Draw(std::string filename,VECTOR2 divSize,VECTOR2 divCnt,VECTOR2 chipOffset);	// ﾌﾟﾚｲﾔｰの描画
	void SetMove(void);

private:
	VECTOR2 pos;		// ﾌﾟﾚｲﾔｰの座標
	PL_STATE state;		// ﾌﾟﾚｲﾔｰの状態
	ANIM_TBL animTbl;	// ｱﾆﾒｰｼｮﾝ
	char key[256];
	int speed;			// ﾊﾞｲｸのｽﾋﾟｰﾄﾞ
};

