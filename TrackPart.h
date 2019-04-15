#pragma once
#include "VECTOR2.h"
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
	~TrackPart();
	Track_Parts GetTrackPartState(void);
private:
	VECTOR2 pos;			//  ﬂ∞¬ÇÃç¿ïW
	square HitBox;			// ìñÇΩÇËîªíË
	Track_Parts Partstate;	// Ç«ÇÃïîïi
};

