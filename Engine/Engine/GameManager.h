#include <iostream>
#include <stdio.h>
#include <string>

class GameManager {
public:
	static GameManager& getInstance() {
		static GameManager instance;
		return instance;
	}

	GameManager(GameManager &&) = delete;	//Override Move Constructor
	GameManager(GameManager const&) = delete;	//Override Copy Constructor
	void operator=(GameManager const&) = delete;	//Override Assignment
	void operator=(GameManager &&) = delete;	//Override Move Assignment

	static void Print();
private:
	GameManager() = default;	//Constructor
	~GameManager() = default;	//Destructor
};