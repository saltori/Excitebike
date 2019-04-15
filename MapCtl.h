#pragma once
#include <vector>
#include <memory>
#include "VECTOR2.h"


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
private:
	const int RoadOffset;		// ���̵̾��
	const int Walloffset;		// �ǂ̵̾��
	VECTOR2 roadPos;			// ���̍��W
	VECTOR2 roadPos2;			// ���̍��W2
	VECTOR2 WallPos;			// �ǂ̍��W

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

