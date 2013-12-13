#ifndef _GAMESTATEMANAGER
#define _GAMESTATEMANAGER

#include <stack>
#include "GameState.h"

class GameStateManager
{
private:
	static GameStateManager* _instance;
	std::stack<GameState> gameStateStack;

	GameStateManager(){};
	GameStateManager(GameStateManager &const){};
	GameStateManager& operator=(GameStateManager const&){};
public:
	static GameStateManager* Instance();
	int PushState(GameState* gamestate);
	void PopState();
	~GameStateManager();
};

#endif
