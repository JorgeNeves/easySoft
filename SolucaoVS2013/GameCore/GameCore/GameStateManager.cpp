#include "GameStateManager.h"

NotGameStateException::NotGameStateException(string source) : Exception("NOT A GAMESTATE", source)
{

}

NotGameStateException::~NotGameStateException()
{

}

GameStateManager* GameStateManager::_instance = nullptr;

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

// Timer

void GameStateManager::CurrentStateTimer(int value)
{
	GetCurrentState()->Update();
	glutPostRedisplay();
}

void GameStateManager::CurrentStateTimerWrapper(int value)
{
	Instance()->CurrentStateTimer(value);
	glutTimerFunc(30, CurrentStateTimerWrapper, value++);
}

// Keyboard input handling

void GameStateManager::KeyboardFuncWrapper(unsigned char key, int x, int y)
{
	Instance()->gameStateStack.top()->HandleInput(key, 0, true);
}

void GameStateManager::KeyboardUpFuncWrapper(unsigned char key, int x, int y)
{
	Instance()->gameStateStack.top()->HandleInput(key, 0, false);
}

void GameStateManager::SpecialFuncWrapper(int key, int x, int y)
{
	Instance()->gameStateStack.top()->HandleInput(0, key, true);
}

void GameStateManager::SpecialUpFuncWrapper(int key, int x, int y)
{
	Instance()->gameStateStack.top()->HandleInput(0, key, false);
}

void GameStateManager::RedrawWrapper()
{
	Instance()->gameStateStack.top()->Draw();
}
