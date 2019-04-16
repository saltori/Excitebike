#pragma once
#include "VECTOR2.h"
#include "FVECTOR2.h"
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
	MAX
};
class TrackPart
{
public:
	TrackPart();
	TrackPart(VECTOR2 pos);
	~TrackPart();
	virtual Track_Parts GetTrackPartState(void) = 0;
	virtual void Draw(void) = 0;
	virtual square GetHitBox(void) = 0;
	virtual void AddPartPos(int speed)=0;
	virtual void Update(void) = 0;
	virtual bool HitCheck(FVECTOR2 pos) = 0;
private:
	VECTOR2 pos;		//  ﬂ∞¬ÇÃç¿ïW
	square HitBox;			// ìñÇΩÇËîªíË
	Track_Parts Partstate;	// Ç«ÇÃïîïi
};

