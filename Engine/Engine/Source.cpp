#include <iostream>
#include <string>
#include <vector>

#include "MonoBehaviour.h"

#include "MemoryManager.h"
#include "FileSystemManager.h"
#include "TextureManager.h"
#include "RenderManager.h"
#include "AnimationManager.h"
#include "PhysicsManager.h"
#include "SoundManager.h"

#include "Singleton.h"

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
	
	for (int j = 0; j < 3; j++){
		for (int i = 0; i < size(subsystemArray); i++) {
			switch(j) {
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

	cout << "Pause..." << endl;
	char c;
	cin >> c;
	return 0;
}