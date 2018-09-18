#ifndef TEXTURE_MANAGER
#define TEXTURE_MANAGER

#include "MonoBehaviour.h"
#include "Singleton.h"

class TextureManager : public MonoBehaviour, public Singleton<TextureManager>
{
public:
	void Start();
	void Update();
	void Shutdown();
};
#endif