#pragma once
#include <memory>
#include <list>
#include "BaseScene.h"
#include "Player.h"
#include "Camera.h"

typedef std::shared_ptr<Player> player_ptr;
typedef std::list<player_ptr> player_list;


class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	void Init(void);
	uniqueBase Update(uniqueBase ub);
	const VECTOR2 &GetDrawOffset(void);
private:
	int MovePos;	// 移動させる
	player_list::iterator player;
	player_list playerList;	// playerをﾘｽﾄで管理したい
	std::unique_ptr<Camera> camera;
	void MakePlayer(VECTOR2 vec);
	VECTOR2 RoadPos;	// 道の座標
	VECTOR2 SuRoadPos;	// 道の座標2



};

