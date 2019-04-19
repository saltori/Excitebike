#pragma once
#include <vector>
#include <memory>
#include "VECTOR2.h"
#include "TrackPart.h"
#include "FVECTOR2.h"

using trackpart_ptr = std::unique_ptr<TrackPart>;
using trackpart_vec = std::vector<trackpart_ptr>;

#define lpMapCtl (MapCtl::GetInstance())

struct RecordTime {
	int BestTime;
	int NowTime;
	int Minutes;
	int Second;
	int Milli;
};

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
	void AddWallpos(FVECTOR2 vec);
	void AddRoadpos(FVECTOR2 vec);
	bool Collision(FVECTOR2 pos,float &speed,PL_STATE &state,float &OHValue);
	void HitEffect(float &speed, PL_STATE &state, float &OHValue);
	void SetGoalFlag(bool flg);
	bool GetGoalFlag(void);
	void StartTime(void);
	RecordTime GetRecordTime(void);
private:
	const float RoadOffset;		// ���̵̾��
	const float Walloffset;		// �ǂ̵̾��
	FVECTOR2 roadPos;			// ���̍��W
	FVECTOR2 roadPos2;			// ���̍��W2
	FVECTOR2 WallPos;			// �ǂ̍��W
	void SetState(Track_Parts state,int PosX);
	trackpart_vec partvec;
	bool GoalFlag;		// �ð�޸ر
	RecordTime recordTime;
	void Measurement(void);		// ���Ԍv��
	void TimeCon(void);	// ���b�ɕϊ�
	bool TimeFlag;
	void SetStage(void);
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

