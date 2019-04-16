#pragma once
#include "TrackPart.h"
class SlopeA :
	public TrackPart
{
public:
	SlopeA();
	SlopeA(VECTOR2 pos);
	~SlopeA();
	Track_Parts GetTrackPartState(void);
	void Draw(void);
	square GetHitBox(void);
	void AddPartPos(int speed);
	void Update(void);
	bool HitCheck(FVECTOR2 pos);
private:
	VECTOR2 pos;			// Êß°Â‚ÌÀ•W
	square HitBox;			// “–‚½‚è”»’è
	Track_Parts Partstate;	// ‚Ç‚Ì•”•i
};

