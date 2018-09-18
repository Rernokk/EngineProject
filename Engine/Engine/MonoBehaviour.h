#ifndef MONOBEHAVIOUR
#define MONOBEHAVIOUR

#include <iostream>
#include <iomanip>

using namespace std;

class MonoBehaviour {
	public:
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Shutdown() = 0;
};

#endif