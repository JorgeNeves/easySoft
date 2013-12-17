#pragma once

#include <stack>
#include <GL\glut.h>
#include "InputManager.h"
#include "Exception.h"
#include "LOCALE_EN.h"

class NotGameStateException : public Exception
{
public:
	NotGameStateException(string source);
	~NotGameStateException();
};

class GameState
{
public:
	GameState(){};
	virtual ~GameState(){};

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

class GameStateManager
{
private:
	static GameStateManager* _instance;
	std::stack<GameState*> gameStateStack;
	InputManager* currentIN;

	GameStateManager(){};
	GameStateManager(GameStateManager &const){};
	GameStateManager& operator=(GameStateManager const&){};

	void CurrentStateTimer(int value);

public:
	static GameStateManager* Instance();
	static void CurrentStateTimerWrapper(int value);
	void PushState(GameState* gamestate);
	void PopState();

	void attachInput(InputManager* input);
	GameState* GetCurrentState();
	~GameStateManager();
};