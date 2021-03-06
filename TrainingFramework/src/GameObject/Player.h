#pragma once

#include<list>
#include<string>
#include "GameConfig.h"
#include "MRectangle.h"
#include "Boom.h"

class Sprite2D;


class Player
{
public:
	Player();
	~Player();

	void setPlayerDirection(int direction);
	void setPlayerSpeed(int speed);
	void setPlayerNumBomb(int numBomb);
	void setPlayerLengthBomb(int lengthBomb);
	void setPlayerStatusLive(int statusLive);
	void setPlayerIsMoving(bool isMoving);
	void setPlayerLocation(int x, int y);		// auto create Rect for player
	void setPrepateNextBoom(bool status);
	void addIdBoomIsStanding(int id);

	int			getPlayerDirection();
	int			getPlayerSpeed();
	int			getPlayerNumBomb();
	int			getPlayerLengthBomb();
	int			getPlayerStatusLive();
	bool		isPlayerMoving();
	int			getPlayerLocationX();
	int			getPlayerLocationY();
	std::string	getPlayerTextureStading(int direction);
	MRectangle	getRectPlayer();
	bool		isPrepareNextBoom();
	std::list<Boom*>* getPlayerListBoom();
	Boom*		getBoomById(int boomId);
	std::list<int> getListIdBoomIsStanding();

	void		movePlayer(int direction);
	void		initBoom();
	void		reLoadBoom();
	int			isCollWithItemPlayer();		//return 0 is true and 1 is false
	void		resetData();
	void		removeIdBoomIsStanding(int id);
	void		updateIsStandingOnBoom();

private:
	void		updatePlayerWithItemPlayer(int kindItem);

	int					p_speed;
	int					p_power;
	int					p_status_live;			// 1: live , 2: is bubbles , 3:is dead
	int					p_direction;			// 1: up , 2: left , 3:down , 4: right
	bool				p_is_move;				// true: isRunning, false:isStanding
	MRectangle			p_rec;					// must Note that the location of rec just the body player
												// it is different than the p_location to draw
	int					p_location_x;
	int					p_location_y;
	std::string			p_texture[PLAYER_TEXTURE_EACH_DIRECTION * 4];
	int					p_size_x;
	int					p_size_y;

	int					p_num_boom;
	std::list<Boom*>	p_list_boom;
	bool				p_isPrepareNextBoom;
	std::list<int>		p_boomIdIsStanding;
};