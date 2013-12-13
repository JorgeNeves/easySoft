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
