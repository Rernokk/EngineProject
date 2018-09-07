#include <iostream>
#include <stdio.h>
#include <string>

class SoundManager {
public:
	static SoundManager& getInstance() {
		static SoundManager instance;
		return instance;
	}

	SoundManager(SoundManager &&) = delete;	//Override Move Constructor
	SoundManager(SoundManager const&) = delete;	//Override Copy Constructor
	void operator=(SoundManager const&) = delete;	//Override Assignment
	void operator=(SoundManager &&) = delete;	//Override Move Assignment

	static void Print();
private:
	SoundManager() = default;	//Constructor
	~SoundManager() = default;	//Destructor
};