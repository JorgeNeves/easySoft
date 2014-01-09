#pragma once

#include <stack>
#include <GL\glut.h>
#include "Exception.h"

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
	virtual void HandleInput(unsigned char key, int special, bool val) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

class GameStateManager
{
private:
	static GameStateManager* _instance;
	std::stack<GameState*> gameStateStack;

	GameStateManager(){};
	GameStateManager(const GameStateManager&){};
	GameStateManager& operator=(const GameStateManager&){};


	// Timer
	void CurrentStateTimer(int value);

public:
	static GameStateManager* Instance();
	static void CurrentStateTimerWrapper(int value);
	static void KeyboardFuncWrapper(unsigned char key, int x, int y);
	static void KeyboardUpFuncWrapper(unsigned char key, int x, int y);
	static void SpecialFuncWrapper(int key, int x, int y);
	static void SpecialUpFuncWrapper(int key, int x, int y);
	static void RedrawWrapper();


	void PushState(GameState* gamestate);
	void PopState();

	GameState* GetCurrentState();
	~GameStateManager();
};