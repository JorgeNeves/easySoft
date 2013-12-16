#pragma once

#include <stack>
#include "GameState.h"
#include "InputManager.h"
#include "Exception.h"
#include "LOCALE_EN.h"

class NotGameStateException : public Exception
{
public:
	NotGameStateException(string source);
	~NotGameStateException();
};

class GameStateManager
{
private:
	static GameStateManager* _instance;
	std::stack<GameState*> gameStateStack;
	static InputManager* currentIN;

	GameStateManager(){};
	GameStateManager(GameStateManager &const){};
	GameStateManager& operator=(GameStateManager const&){};
public:
	static GameStateManager* Instance();
	void PushState(GameState* gamestate);
	void PopState();

	void attachInput(InputManager* input);
	GameState* GetCurrentState();
	~GameStateManager();
};