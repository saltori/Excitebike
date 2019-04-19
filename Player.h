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
	NOSEMANUAL,	// 逆ｳｨﾘｰ
	FINISH,		// ゴール
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
	bool SetAnim(std::string animName);
	void AddanimCnt(int aniCnt);
	PL_STATE GetState(void);
private:
	FVECTOR2 pos;			// ﾌﾟﾚｲﾔｰの座標
	FVECTOR2 v;				//　加速度
	PL_STATE state;			// ﾌﾟﾚｲﾔｰの状態
	ANIM_TBL animTbl;		// ｱﾆﾒｰｼｮﾝ
	char key[256];
	char keyOld[256];
	float speed;				// ﾊﾞｲｸのｽﾋﾟｰﾄﾞ
	std::string imageName;
	VECTOR2 divSize;		//// 描画ﾁｯﾌﾟのｻｲｽﾞ
	VECTOR2 divCnt;		// 描画ﾁｯﾌﾟ数（縦横）
	VECTOR2 chipOffset; // 描画ﾁｯﾌﾟのイメージIDのｵﾌｾｯﾄ
	std::map<std::string, int[static_cast<int>(ANIM_TBL::MAX)]> animTable;	// ｱﾆﾒｰｼｮﾝのﾃｰﾌﾞﾙ
	std::string animName;	// 選択中のｱﾆﾒｰｼｮﾝ
	int animCnt;
	bool AddAnim(std::string animName, int id_x, int id_y, int frame, int inv);
	bool initAnim(void);
	bool OHflag;					// ｵｰﾊﾞｰﾋｰﾄかどうかのﾌﾗｸﾞ
	square engineBox;				// ｴﾝｼﾞﾝ
	float OHValue;					// ｵｰﾊﾞｰﾋｰﾄ
	int Flash;				// ｴﾝｼﾞﾝを点滅させる用
	bool animCntAddflg;				// ｱﾆﾒｰｼｮﾝのﾙｰﾌﾟ用
	const float Gravity;			// 重力
	float JumpHeight;				// ｼﾞｬﾝﾌﾟの高さ]
	float PlayerGround;				// ﾌﾟﾚｲﾔｰのいる地面の座標
	void Fall(void);				// 落下処理	
	void DebugDraw(void);
};

