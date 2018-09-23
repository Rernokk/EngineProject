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

	Vector3* vec = new Vector3(1, 1, 1);
	//cout << vec->x << ", " << vec->y << ", " << vec->z << endl;
	*vec = (*vec) * 3;
	cout << *vec << endl;
	*vec = (*vec) + new Vector3(1, -1, 1);
	cout << *vec << endl;
	*vec = (*vec) - new Vector3(1, -1, 1);
	cout << *vec << endl;
	vec = new Vector3(1, 0, 0);
	Vector3* vecB = new Vector3(5, 1, 0);
	cout << *vecB << endl;
	float val = (*vec) * (*vecB);
	cout << "Dot: " << val << endl;
	*vec = vec->Normalize();
	cout << *vec << endl;
	val = vec->Length();
	cout << "Length: " << val << endl;

	cout << "Pause..." << endl;
	char c;
	cin >> c;
	return 0;
}