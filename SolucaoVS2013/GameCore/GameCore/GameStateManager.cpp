#include "GameStateManager.h"

NotGameStateException::NotGameStateException(string source) : Exception(EX_NOTGAMESTATE, source)
{

}

NotGameStateException::~NotGameStateException()
{

}

GameStateManager* GameStateManager::_instance = nullptr;
InputManager* GameStateManager::currentIN = nullptr;


GameStateManager* GameStateManager::Instance()
{
	if (!_instance)
	{
		_instance = new GameStateManager;
	}
	return _instance;
}

void GameStateManager::PushState(GameState* gamestate)
{
	if (GameState* test = dynamic_cast<GameState*>(gamestate))
	{
		gameStateStack.push(gamestate);
		gamestate->Load();
		return;
	}
	throw new NotGameStateException("GameStateManager::PushState");
}

void GameStateManager::PopState()
{
	GameState* gs = nullptr;
	if (gameStateStack.size() > 0)
	{
		gs = gameStateStack.top();
		gs->Unload();
		gameStateStack.pop();
	}
	else
	{
		throw new Exception();
	}
	return;
}

void GameStateManager::attachInput(InputManager* input)
{
	if (input != NULL)
		currentIN = input;
}

GameState* GameStateManager::GetCurrentState()
{
	return gameStateStack.top();
}