#ifndef RENDER_MANAGER
#define RENDER_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"

class RenderManager : public MonoBehaviour, public Singleton<RenderManager>
{
public:
	void Start();
	void Update();
	void Shutdown();
};
#endif