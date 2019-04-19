#pragma once
#include "TrackPart.h"
class Finish :
	public TrackPart
{
public:
	Finish();
	Finish(int x);
	~Finish();
	Track_Parts GetTrackPartState(void);
	void Draw(void);
	square GetHitBox(void);
	void AddPartPos(int speed);
	void Update(void);
	bool Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue);
	void HitEffect(float &speed, PL_STATE &state, float &OHValue);
private:
	VECTOR2 pos;		// �߰̍��W
	square HitBox;			// �����蔻��
	Track_Parts Partstate;	// �ǂ̕��i
};

