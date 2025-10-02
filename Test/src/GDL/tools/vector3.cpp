#include "../../../include/GDL/tools/vector3.h"
#include <cmath>

namespace gdl::tools {

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(f32 x, f32 y, f32 z) : x(x), y(y), z(z) {}

f32 Vector3::mag(){
	return std::sqrt(x * x + y * y + z * z);
}
Vector3 Vector3::nor(){
	f32 n = this->mag();

	return Vector3(x / n, y / n, z / n);
}
f32 Vector3::dist(const Vector3& v){
	Vector3 d(v.x - x, v.y - y, v.z - z);

	return d.mag();
}

Vector3 Vector3::operator+ (const Vector3& v){
	return Vector3(x + v.x, y + v.y, z + v.z);
}
Vector3 Vector3::operator- (const Vector3& v){
	return Vector3(x - v.x, y - v.y, z - v.z);
}
Vector3 Vector3::operator* (f32 v){
	return Vector3(x * v, y * v, z * v);
}
Vector3 Vector3::operator/ (f32 v){
	return Vector3(x / v, y / v, z / v);
}

void Vector3::operator+= (const Vector3& v){
	x += v.x;
	y += v.y;
	z += v.z;
}
void Vector3::operator-= (const Vector3& v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
}
void Vector3::operator*= (f32 v){
	x *= v;
	y *= v;
	z *= v;
}
void Vector3::operator/= (f32 v){
	x /= v;
	y /= v;
	z /= v;
}


}




