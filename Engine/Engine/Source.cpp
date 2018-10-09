#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <mutex>

#include "MonoBehaviour.h"

#include "MemoryManager.h"
#include "FileSystemManager.h"
#include "TextureManager.h"
#include "RenderManager.h"
#include "AnimationManager.h"
#include "PhysicsManager.h"
#include "SoundManager.h"
#include "GameWorld.h"

#include "Singleton.h"
#include "Vector3.h"

#define MS_PER_FRAME 1.0/10.0

using namespace std;

int main() {
	//MonoBehaviour * subsystemArray[8];
	vector<MonoBehaviour*> subsystemArray;
	subsystemArray.push_back(&(MemoryManager::getInstance()));
	subsystemArray.push_back(&(FileSystemManager::getInstance()));
	subsystemArray.push_back(&(TextureManager::getInstance()));
	subsystemArray.push_back(&(RenderManager::getInstance()));
	subsystemArray.push_back(&(AnimationManager::getInstance()));
	subsystemArray.push_back(&(PhysicsManager::getInstance()));
	subsystemArray.push_back(&(SoundManager::getInstance()));

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < size(subsystemArray); i++) {
			switch (j) {
			case(0):
				subsystemArray[i]->Start();
				break;

			case(1):
				subsystemArray[i]->Update();
				break;

			case(2):
				subsystemArray[i]->Shutdown();
				break;
			}
		}
		cout << endl;
	}

	char c;
	char playerInput = 'x';
	GameWorld world = GameWorld();
	world.Start();
	world.playerObj = GameWorld::player();
	thread f (&GameWorld::Render, world, world.renderState, MS_PER_FRAME);
	thread input (&GameWorld::InputHandler, world, &playerInput, MS_PER_FRAME);

	auto prev = chrono::high_resolution_clock::now();
	while (true) {
		auto current = chrono::high_resolution_clock::now();

		world.SetDeltaTime(chrono::duration_cast<chrono::milliseconds>(current - prev).count());
		world.input = &(playerInput);
		world.Update();

		prev = chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds((int)((MS_PER_FRAME * 1000 - chrono::duration_cast<chrono::milliseconds>(current - prev).count()))));
		
	}

	cin >> c;
	return 0;
}