#include "GameStateManager.h"

GameStateManager* GameStateManager::_instance = nullptr;


GameStateManager* GameStateManager::Instance()
{
	if (!_instance)
	{
		_instance = new GameStateManager;
	}
	return _instance;
}

int GameStateManager::PushState(GameState* gamestate)
{
	if (GameState* test = dynamic_cast<GameState*>(gamestate))
	{
		gameStateStack.push(gamestate);
		return 0;
	}
	return -1;
}

GameState* GameStateManager::GetCurrentState()
{
	return gameStateStack.top();
}
