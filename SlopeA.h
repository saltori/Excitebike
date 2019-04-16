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
	VECTOR2 pos;			// �߰̍��W
	square HitBox;			// �����蔻��
	Track_Parts Partstate;	// �ǂ̕��i
};

