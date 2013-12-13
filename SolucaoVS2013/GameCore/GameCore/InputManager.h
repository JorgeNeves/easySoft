#ifndef _INPUTMANAGER
#define _INPUTMANAGER

class InputManager
{
private:
	// members
	static InputManager* _instance;
	unsigned char keystates[255];
	// methods
	void virtual KeyboardFunc(unsigned char key, int x, int y);
	void virtual KeyboardUpFunc(unsigned char key, int x, int y);

	// private object creators for singleton implementation
	InputManager();
	InputManager(InputManager& const){};
	InputManager& operator=(InputManager& const){};


public:
	static InputManager* Instance();
	static void KeyboardFuncWrapper(unsigned char key, int x, int y);
	static void KeyboardUpFuncWrapper(unsigned char key, int x, int y);
	(unsigned char)* GetKeyStates();
	~InputManager();
};

#endif