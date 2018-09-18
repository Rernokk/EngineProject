#ifndef FILE_SYSTEM_MANAGER
#define FILE_SYSTEM_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"

class FileSystemManager : public MonoBehaviour, public Singleton<FileSystemManager>
{
public:
	void Start();
	void Update();
	void Shutdown();
};
#endif