#include "../../../include/GDL/tools/vector2.h"
#include <cmath>

namespace gdl::tools {

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(f32 x, f32 y) : x(x), y(y) {}

f32 Vector2::mag(){
	return std::sqrt(x * x + y * y);
}
Vector2 Vector2::nor(){
	f32 n = this->mag();

	return Vector2(x / n, y / n);
}
f32 Vector2::dist(const Vector2& v){
	Vector2 d(v.x - x, v.y - y);

	return d.mag();
}

Vector2 Vector2::operator+ (const Vector2& v){
	return Vector2(x + v.x, y + v.y);
}
Vector2 Vector2::operator- (const Vector2& v){
	return Vector2(x - v.x, y - v.y);
}
Vector2 Vector2::operator* (f32 v){
	return Vector2(x * v, y * v);
}
Vector2 Vector2::operator/ (f32 v){
	return Vector2(x / v, y / v);
}

void Vector2::operator+= (const Vector2& v){
	x += v.x;
	y += v.y;
}
void Vector2::operator-= (const Vector2& v){
	x -= v.x;
	y -= v.y;
}
void Vector2::operator*= (f32 v){
	x *= v;
	y *= v;
}
void Vector2::operator/= (f32 v){
	x /= v;
	y /= v;
}



}




