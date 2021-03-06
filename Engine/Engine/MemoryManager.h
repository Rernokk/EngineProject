#ifndef MEMORY_MANAGER
#define MEMORY_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"
#include "IMemoryManager.h"

class MemoryManager : public MonoBehaviour, public Singleton<MemoryManager>, public IMemoryManager
{
	struct FreeStore {
		FreeStore* next;
	};

	void ExpandPoolSize(size_t size);
	void CleanUp();
	FreeStore* freeStoreHead;

	public:
		void Start();
		void Update();
		void Shutdown();

		void* Allocate(size_t size);
		void Free (void* ptr);

		MemoryManager() {
			freeStoreHead = 0;
			ExpandPoolSize(1);
		}

		virtual ~MemoryManager() {
			CleanUp();
		}
};
#endif