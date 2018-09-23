#ifndef VECTOR3
#define VECTOR3
#include <iostream>

using namespace std;

class Vector3 {
public:
	float x, y, z;

	friend ostream& operator<<(ostream& os, const Vector3& vec);
	Vector3 operator + (Vector3* other);
	Vector3 operator - (Vector3* other);
	Vector3 operator * (float scalar);
	Vector3 operator / (float scalar);
	float operator * (Vector3 dot);

	void* operator new(size_t size);
	void* operator new[](size_t size);
	void	operator delete(void* ptrData);
	void	operator delete[](void* ptrData);

	Vector3 Normalize();
	float		Length();

	Vector3();																//Empty Constructor
	~Vector3() = default;											//Destructor
	Vector3(float x, float y, float z);				//Constructor w/ Params

protected:

private:
};

#endif