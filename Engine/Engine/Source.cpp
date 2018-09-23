#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "MonoBehaviour.h"

#include "MemoryManager.h"
#include "FileSystemManager.h"
#include "TextureManager.h"
#include "RenderManager.h"
#include "AnimationManager.h"
#include "PhysicsManager.h"
#include "SoundManager.h"

#include "Singleton.h"
#include "Vector3.h"

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
	auto t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < 5000; j++){
		Vector3* ptr;
		for (int i = 0; i < 1000; i++) {
			ptr = (Vector3*) malloc(sizeof(Vector3));
			(*ptr) = Vector3();
			ptr = NULL;
			free(ptr);
		}
	}
	auto t2 = chrono::high_resolution_clock::now();
	cout << "<New> Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;

	t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < 5000; j++) {
		Vector3* ptr;
		for (int i = 0; i < 1000; i++) {
			ptr = new Vector3();
			delete (ptr);
		}
	}
	t2 = chrono::high_resolution_clock::now();
	cout << "<Allocate> Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;

	/*Vector3* vec = new Vector3(1, 1, 1);
	void* space = MemoryManager::getInstance().Allocate(sizeof(Vector3));
	space = new Vector3(1,1,1);*/

	cout << "Pause..." << endl;
	char c;
	cin >> c;
	return 0;
}