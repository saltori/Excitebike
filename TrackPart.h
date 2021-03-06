#pragma once
#include "VECTOR2.h"
#include "FVECTOR2.h"
#include "Player.h"
enum class Track_Parts
{
	SLOPE_A,
	SLOPE_B,
	SLOPE_C,
	SLOPE_D,
	SLOPE_E,
	SLOPE_F,
	SLOPE_G,
	SLOPE_H,
	AXCEL,
	FENCE,
	LONG_TURF,
	WIDE_TURF,
	MISHMASH,
	SWAMP,
	FNISH,
	MAX
};
class TrackPart
{
public:
	TrackPart();
	TrackPart(int y);
	~TrackPart();
	virtual Track_Parts GetTrackPartState(void) = 0;
	virtual void Draw(void) = 0;
	virtual square GetHitBox(void) = 0;
	virtual void AddPartPos(int speed)=0;
	virtual void Update(void) = 0;
	virtual bool Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue) = 0;
	virtual void HitEffect(float &speed,PL_STATE &state,float &OHValue) = 0;
private:
	VECTOR2 pos;		// ﾊﾟｰﾂの座標
	square HitBox;			// 当たり判定
	Track_Parts Partstate;	// どの部品
};

