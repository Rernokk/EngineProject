#ifndef IMEMORYMANAGER
#define IMEMORYMANAGER

class IMemoryManager {
	public:
		virtual void* Allocate(size_t size) = 0;
		virtual void Free (void* ptr) = 0;
};

#endif