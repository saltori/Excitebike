#pragma once
#include "TrackPart.h"
class Swamp :
	public TrackPart
{
public:
	Swamp();
	Swamp(int x);
	~Swamp();
	Track_Parts GetTrackPartState(void);
	void Draw(void);
	square GetHitBox(void);
	void AddPartPos(int speed);
	virtual void Update(void);
	bool Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue);
	void HitEffect(float &speed, PL_STATE &state, float &OHValue);
private:
	VECTOR2 pos;		// �߰̍��W
	square HitBox;			// �����蔻��(�㕔)
	square HitBox2;			// �����蔻��(����)
	Track_Parts Partstate;	// �ǂ̕��i
};

