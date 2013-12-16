#pragma once
class GameStateController
{
public:
	GameStateController();
	virtual ~GameStateController();
	virtual void update(float delta) = 0;
};
 
