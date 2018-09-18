#ifndef ANIMATION_MANAGER
#define ANIMATION_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"

class AnimationManager : public MonoBehaviour, public Singleton<AnimationManager>
{
public:
	void Start();
	void Update();
	void Shutdown();
};
#endif