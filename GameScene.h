#pragma once
#include <memory>
#include <list>
#include "BaseScene.h"
#include "Player.h"
#include "FVECTOR2.h"

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
private:
	player_list::iterator player;
	player_list playerList;	// player��ؽĂŊǗ�������
	void MakePlayer(FVECTOR2 vec);
	int Flash;
	square FlashBox;	// �ްق������ɓ_�ł�����



};

