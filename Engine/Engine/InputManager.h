#include <iostream>
#include <stdio.h>
#include <string>

class InputManager {
public:
	static InputManager& getInstance() {
		static InputManager instance;
		return instance;
	}

	InputManager(InputManager &&) = delete;	//Override Move Constructor
	InputManager(InputManager const&) = delete;	//Override Copy Constructor
	void operator=(InputManager const&) = delete;	//Override Assignment
	void operator=(InputManager &&) = delete;	//Override Move Assignment

	static void Print();
private:
	InputManager() = default;	//Constructor
	~InputManager() = default;	//Destructor
};