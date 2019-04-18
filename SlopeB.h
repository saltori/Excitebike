#pragma once
#include "TrackPart.h"
class SlopeB:
	public TrackPart

{
public:
	SlopeB();
	SlopeB(int x);
	~SlopeB();
	Track_Parts GetTrackPartState(void);
	void Draw(void);
	square GetHitBox(void);
	void AddPartPos(int speed);
	void Update(void);
	bool HitCheck(FVECTOR2 pos);
	void HitEffect(float &speed, PL_STATE &state, float &OHValue);
private:
	VECTOR2 pos;			// Êß°Â‚ÌÀ•W
	square HitBox;			// “–‚½‚è”»’è
	Track_Parts Partstate;	// ‚Ç‚Ì•”•i
};

