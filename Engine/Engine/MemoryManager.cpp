#include "MemoryManager.h"
#include "Vector3.h"

#define POOL_SIZE 32

void MemoryManager::Start() {
	cout << "Memory Manager Start" << endl;
	freeStoreHead = 0;
	ExpandPoolSize(1);
}

void MemoryManager::Update() {
	cout << "Memory Manager Update" << endl;
}

void MemoryManager::Shutdown() {
	cout << "Memory Manager Shutdown" << endl;
}

void* MemoryManager::Allocate(size_t size) {
	if (freeStoreHead == 0) {
		ExpandPoolSize(size);
	}
	FreeStore* head = freeStoreHead;
	freeStoreHead = head->next;
	return head;
}

void MemoryManager::Free(void* ptr) {
	FreeStore* head = static_cast <FreeStore*> (ptr);
	head->next = freeStoreHead;
	freeStoreHead = head;
}

void MemoryManager::ExpandPoolSize(size_t iSize) {
	size_t size = (iSize > sizeof(FreeStore*) ? iSize : sizeof(FreeStore*));
	FreeStore* head = reinterpret_cast<FreeStore*> (new char[size]);
	freeStoreHead = head;

	for (int i = 0; i < POOL_SIZE; i++) {
		head->next = reinterpret_cast<FreeStore*> (new char[size]);
		head = head->next;
	}

	head->next = 0;
}

void MemoryManager::CleanUp() {
	FreeStore* ptr = freeStoreHead;
	for (; ptr; ptr = freeStoreHead) {
		freeStoreHead = freeStoreHead->next;
		delete[] ptr;
	}
}