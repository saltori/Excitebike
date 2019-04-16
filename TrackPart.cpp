#include "TrackPart.h"



TrackPart::TrackPart()
{
}

TrackPart::TrackPart(VECTOR2 pos)
{
	this->pos = pos;
}


TrackPart::~TrackPart()
{
}

Track_Parts TrackPart::GetTrackPartState(void)
{
	return Track_Parts::MAX;
}




