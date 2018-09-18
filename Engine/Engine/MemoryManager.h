#ifndef MEMORY_MANAGER
#define MEMORY_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"

class MemoryManager : public MonoBehaviour, public Singleton<MemoryManager>
{
	public:
		void Start();
		void Update();
		void Shutdown();
};
#endif