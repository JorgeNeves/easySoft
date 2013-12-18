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

GameState* GameStateManager::GetCurrentState()
{
	return gameStateStack.top();
}

// Keyboard input handling

void GameStateManager::KeyboardFunc(unsigned char key, int x, int y)
{
	gameStateStack.top()->HandleInput(key, 0, true);
}

void GameStateManager::KeyboardUpFunc(unsigned char key, int x, int y)
{
	gameStateStack.top()->HandleInput(key, 0, false);
}

void GameStateManager::KeyboardFuncWrapper(unsigned char key, int x, int y)
{
	_instance->KeyboardFunc(key, x, y);
}

void GameStateManager::KeyboardUpFuncWrapper(unsigned char key, int x, int y)
{
	_instance->KeyboardUpFunc(key, x, y);
}