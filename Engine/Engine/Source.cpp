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

	cout << "Attempting to normalize zero vector:" << endl;
	Vector3* zVec = new Vector3();
	cout << *zVec << endl;
	*zVec = zVec->Normalize();
	cout << *zVec << endl;

	int net = 0;
	int objCount = 10000;
	int iterationCount = 5000;

	auto t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < iterationCount; j++){
		Vector3* ptr;
		for (int i = 0; i < objCount; i++) {
			ptr = (Vector3*) malloc(sizeof(Vector3));
			(*ptr) = Vector3();
			ptr = NULL;
			free(ptr);
		}
	}
	auto t2 = chrono::high_resolution_clock::now();
	cout << "Traditional: Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
	cout << "Allocated and deallocated memory for " << objCount << " Vector3s " << iterationCount << " times." << endl << endl;
	net = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();

	t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < iterationCount; j++) {
		Vector3* ptr;
		for (int i = 0; i < objCount; i++) {
			ptr = new Vector3();
			delete (ptr);
		}
	}
	t2 = chrono::high_resolution_clock::now();
	cout << "MemoryManager:  Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
	cout << "Allocated and deallocated memory for " << objCount << " Vector3s " << iterationCount << " times." << endl << endl;
	net -= chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout << "Difference of " << net << " milliseconds when using our new methods." << endl << endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;

	//Strings
	//Original
	t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < iterationCount; j++) {
		string* ptr;
		for (int i = 0; i < objCount; i++) {
			ptr = (string*)malloc(sizeof(string));
			//(*ptr) = 25.0;
			ptr = NULL;
			free(ptr);
		}
	}
	t2 = chrono::high_resolution_clock::now();
	cout << "Traditional: Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
	cout << "Allocated and deallocated memory for " << objCount << " Strings " << iterationCount << " times." << endl << endl;

	//Extended
	t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < iterationCount; j++) {
		string* ptr;
		for (int i = 0; i < objCount; i++) {
			ptr = (string*)MemoryManager::getInstance().Allocate(sizeof(string));
			MemoryManager::getInstance().Free(ptr);
		}
	}
	t2 = chrono::high_resolution_clock::now();
	cout << "MemoryManager:  Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
	cout << "Allocated and deallocated memory for " << objCount << " Strings " << iterationCount << " times." << endl << endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;

	//Doubles
	//Original
	t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < iterationCount; j++) {
		double* ptr;
		for (int i = 0; i < objCount; i++) {
			ptr = (double*) malloc(sizeof(double));
			(*ptr) = 25.0;
			ptr = NULL;
			free(ptr);
		}
	}
	t2 = chrono::high_resolution_clock::now();
	cout << "Traditional: Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
	cout << "Allocated and deallocated memory for " << objCount << " Doubles " << iterationCount << " times." << endl << endl;

	//Extended
	t1 = chrono::high_resolution_clock::now();
	for (int j = 0; j < iterationCount; j++) {
		double* ptr;
		for (int i = 0; i < objCount; i++) {
			ptr = (double*) MemoryManager::getInstance().Allocate(sizeof(double));
			MemoryManager::getInstance().Free(ptr);
		}
	}
	t2 = chrono::high_resolution_clock::now();
	cout << "MemoryManager:  Time Taken: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds." << endl;
	cout << "Allocated and deallocated memory for " << objCount << " Doubles " << iterationCount << " times." << endl << endl;

	cout << "Pause..." << endl;
	char c;
	cin >> c;
	return 0;
}