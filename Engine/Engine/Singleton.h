#ifndef SINGLETON
#define SINGLETON

#include <iostream>
#include <string>

template <class T>
class Singleton
{
	public:
		static T& getInstance(){
			static T instance;
			return instance;
		};

		static void Print() { cout << "What" << endl; };

		Singleton<T>(const Singleton&) = delete;
		Singleton<T>& operator= (const Singleton) = delete;

	protected:
		Singleton() {};
};

#endif