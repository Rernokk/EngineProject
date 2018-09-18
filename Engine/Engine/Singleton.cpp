#include "Singleton.h"

Singleton::Singleton& getInstance() {
	static Singleton instance;
	return instance;
};