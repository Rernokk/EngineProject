#include "GameBehaviour.h"
#include <iostream>

class TestBehaviour : public GameBehaviour {
	public:
		void GameBehaviour::Print();
		TestBehaviour() = default;
		~TestBehaviour() = default;
};