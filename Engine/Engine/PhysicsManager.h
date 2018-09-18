#ifndef PHYSICS_MANAGER
#define PHYSICS_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"

class PhysicsManager : public MonoBehaviour, public Singleton<PhysicsManager>
{
public:
	void Start();
	void Update();
	void Shutdown();
};
#endif