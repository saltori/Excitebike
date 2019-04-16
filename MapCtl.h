#pragma once
#include <vector>
#include <memory>
#include "VECTOR2.h"
#include "TrackPart.h"
#include "FVECTOR2.h"

using trackpart_ptr = std::unique_ptr<TrackPart>;
using trackpart_vec = std::vector<trackpart_ptr>;

#define lpMapCtl (MapCtl::GetInstance())

class MapCtl
{
public:
	static MapCtl &GetInstance(void)
	{
		return *s_Instance;
	}
	VECTOR2 GetAreaSize(void);
	VECTOR2 GetViewSize(void);
	void MapDraw(void);
	void Update(void);
	char key[256];
	void AddWallpos(VECTOR2 vec);
	void AddRoadpos(VECTOR2 vec);
	bool HitCheck(FVECTOR2 pos);
private:
	const int RoadOffset;		// 道のｵﾌｾｯﾄ
	const int Walloffset;		// 壁のｵﾌｾｯﾄ
	VECTOR2 roadPos;			// 道の座標
	VECTOR2 roadPos2;			// 道の座標2
	VECTOR2 WallPos;			// 壁の座標
	void SetState(Track_Parts state,VECTOR2 pos);
	trackpart_vec partvec;
	struct MapCtlDeleter
	{
		void operator()(MapCtl* mapCtl) const
		{
			delete mapCtl;
		}

	};
	MapCtl();
	~MapCtl();
	static std::unique_ptr<MapCtl, MapCtlDeleter> s_Instance;
};

