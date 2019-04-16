#pragma once

#include <string>
#include <map>
#include "VECTOR2.h"
#include "FVECTOR2.h"


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

constexpr int PlayerDivSize		= 24;	// ﾌﾟﾚｲﾔｰのｻｲｽﾞ
constexpr int PlayerDivCnt		= 6;	// ﾌﾟﾚｲﾔｰのｺﾏ数
constexpr int PlayerChipOffsetX = 1;	// 描画ﾁｯﾌﾟのｵﾌｾｯﾄ
constexpr int PlayerChipOffsetY = 0;	// 描画ﾁｯﾌﾟのｵﾌｾｯﾄ
constexpr float GroundPos		= 200.0f;	// 地面か空中化の分岐点

class Player
{
public:
	Player();
	Player(FVECTOR2 pos);
	~Player();
	void Init(std::string filename,VECTOR2 divSize,VECTOR2 divCnt,VECTOR2 chipOffset);	// ﾌﾟﾚｲﾔｰの描画
	void Draw(void);
	void SetMove(void);
	const VECTOR2 &GetPos(void);
	const int GetplayerSpeed(void);
	bool SetAnim(std::string animName);
	void AddanimCnt(int aniCnt);

private:
	FVECTOR2 pos;			// ﾌﾟﾚｲﾔｰの座標
	PL_STATE state;			// ﾌﾟﾚｲﾔｰの状態
	ANIM_TBL animTbl;		// ｱﾆﾒｰｼｮﾝ
	char key[256];
	char keyOld[256];
	int speed;				// ﾊﾞｲｸのｽﾋﾟｰﾄﾞ
	std::string imageName;
	VECTOR2 divSize;		//// 描画ﾁｯﾌﾟのｻｲｽﾞ
	VECTOR2 divCnt;		// 描画ﾁｯﾌﾟ数（縦横）
	VECTOR2 chipOffset; // 描画ﾁｯﾌﾟのイメージIDのｵﾌｾｯﾄ
	std::map<std::string, int[static_cast<int>(ANIM_TBL::MAX)]> animTable;	// ｱﾆﾒｰｼｮﾝのﾃｰﾌﾞﾙ
	std::string animName;	// 選択中のｱﾆﾒｰｼｮﾝ
	unsigned int animCnt;
	bool AddAnim(std::string animName, int id_x, int id_y, int frame, int inv);
	bool initAnim(void);
	bool OHflag;					// ｵｰﾊﾞｰﾋｰﾄかどうかのﾌﾗｸﾞ
	square engineBox;				// ｴﾝｼﾞﾝ
	float OHValue;					// ｵｰﾊﾞｰﾋｰﾄ
	int engineFlash;				// ｴﾝｼﾞﾝを点滅させる用
	bool animCntAddflg;				// ｱﾆﾒｰｼｮﾝのﾙｰﾌﾟ用
};

