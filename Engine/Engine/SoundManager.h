#ifndef SOUND_MANAGER
#define SOUND_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"

class SoundManager : public MonoBehaviour, public Singleton<SoundManager>
{
public:
	void Start();
	void Update();
	void Shutdown();
};
#endif