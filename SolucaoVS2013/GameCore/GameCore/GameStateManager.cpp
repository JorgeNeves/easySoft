#include "GameStateManager.h"

NotGameStateException::NotGameStateException(string source) : Exception(EX_NOTGAMESTATE, source)
{

}

NotGameStateException::~NotGameStateException()
{

}

GameStateManager* GameStateManager::_instance = nullptr;

void GameStateManager::CurrentStateTimer(int value)
{
	GetCurrentState()->Update();
}



GameStateManager* GameStateManager::Instance()
{
	if (!_instance)
	{
		_instance = new GameStateManager;
	}
	return _instance;
}

void GameStateManager::CurrentStateTimerWrapper(int value)
{
	_instance->CurrentStateTimer(value);
	glutTimerFunc(30, CurrentStateTimerWrapper, 10);
}

void GameStateManager::PushState(GameState* gamestate)
{
	if (GameState* test = dynamic_cast<GameState*>(gamestate))
	{
		gameStateStack.push(gamestate);
		gamestate->Load();
		printf("\tSize:%d\n", gameStateStack.size());
		return;
	}
	throw new NotGameStateException("GameStateManager::PushState");
}

void GameStateManager::PopState()
{
	GameState* gs = nullptr;
	if (gameStateStack.size() > 1)
	{
		gs = gameStateStack.top();
		gs->Unload();
		gameStateStack.pop();
		printf("\tSize:%d\n", gameStateStack.size());
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