#include "InputManager.h"
#include <stdio.h>

InputManager* InputManager::_instance = nullptr;

InputManager::InputManager()
{
	// key states initialization to false (non pressed)
	for (int i = 0; i < 256; i++)
	{
		keystates[i] = false;
	}
}

InputManager* InputManager::Instance()
{
	if (!_instance)
	{
		_instance = new InputManager;
	}
	return _instance;
}

void InputManager::KeyboardFunc(unsigned char key, int x, int y)
{
	keystates[key] = true;
	printf("%c 1 (down)\n", key);
}

void InputManager::KeyboardUpFunc(unsigned char key, int x, int y)
{
	keystates[key] = false;
	printf("%c 0 ( up )\n", key);
}

void InputManager::KeyboardFuncWrapper(unsigned char key, int x, int y)
{
	_instance->KeyboardFunc(key, x, y);
}

void InputManager::KeyboardUpFuncWrapper(unsigned char key, int x, int y)
{
	_instance->KeyboardUpFunc(key, x, y);
}

unsigned char* InputManager::GetKeyStates()
{
	return keystates;
}