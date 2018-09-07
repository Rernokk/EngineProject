#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "GameManager.h"
#include "SoundManager.h"
#include "InputManager.h"

#include "TestBehaviour.h"

using namespace std;

int main() {
	char c;
	cout << "Hi" << endl;
	GameManager::Print();
	SoundManager::Print();
	InputManager::Print();

	TestBehaviour behaviour;
	behaviour.strOut = "THIS IS A BEHAVIOUR";
	behaviour.Print();

	cin >> c;

	return 0;
}