#pragma once
#include "TrackPart.h"
class SlopeA :
	public TrackPart
{
public:
	SlopeA();
	SlopeA(int x);
	~SlopeA();
	Track_Parts GetTrackPartState(void);
	void Draw(void);
	square GetHitBox(void);
	void AddPartPos(int speed);
	void Update(void);
	bool Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue);
	void HitEffect(float &speed, PL_STATE &state, float &OHValue);
private:
	VECTOR2 pos;			// ﾊﾟｰﾂの座標
	square HitBox;			// 当たり判定
	Track_Parts Partstate;	// どの部品
};

