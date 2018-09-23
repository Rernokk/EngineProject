#include "Vector3.h"
#include "MemoryManager.h"
#include <math.h>
#include <iostream>


void* Vector3::operator new(size_t size) {
	return MemoryManager::getInstance().Allocate(size);
}
void* Vector3::operator new[] (size_t size) {
	return MemoryManager::getInstance().Allocate(size);
}

void Vector3::operator delete(void* ptr) {
	MemoryManager::getInstance().Free(ptr);
}
void Vector3::operator delete [](void* ptr) {
	MemoryManager::getInstance().Free(ptr);
}

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}
Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator* (float scalar) {
	return Vector3(scalar * x, scalar * y, scalar * z);
}

Vector3 Vector3::operator/ (float scalar) {
	return Vector3(scalar / x, scalar / y, scalar / z);
}

float Vector3::operator* (Vector3 dot) {
	return x * dot.x + y * dot.y + z * dot.z;
}

Vector3 Vector3::operator+ (Vector3* other) {
	return Vector3(x + other->x, y + other->y, z + other->z);
}

Vector3 Vector3::operator- (Vector3* other) {
	return Vector3(x - other->x, y - other->y, z - other->z);
}

Vector3 Vector3::Normalize() {
	try {
	}
	catch (int e) {
		cout << "Error" << endl;
	}
	return Vector3(x / Length(), y / Length(), z / Length());
}

float Vector3::Length() {
	return sqrt((x*x) + (y * y) + (z * z));
}

ostream & operator <<(ostream & os, const Vector3& vec)
{
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return os;
}
