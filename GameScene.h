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
	player_list::iterator player;
	player_list playerList;	// player‚ğØ½Ä‚ÅŠÇ—‚µ‚½‚¢

	std::unique_ptr<Camera> camera;
	void MakePlayer(VECTOR2 vec);



};

