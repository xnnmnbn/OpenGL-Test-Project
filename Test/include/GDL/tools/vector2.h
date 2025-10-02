#pragma once

#include "typedefs.h"

namespace gdl::tools {

class Vector2{
public:
	f32 x;
	f32 y;

	Vector2();
	Vector2(f32 x, f32 y);

	f32 mag();
	Vector2 nor();
	f32 dist(const Vector2& v);

	Vector2 operator+ (const Vector2& v);
	Vector2 operator- (const Vector2& v);
	Vector2 operator* (f32 v);
	Vector2 operator/ (f32 v);

	void operator+= (const Vector2& v);
	void operator-= (const Vector2& v);
	void operator*= (f32 v);
	void operator/= (f32 v);



};

}





