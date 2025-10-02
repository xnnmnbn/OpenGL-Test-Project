#pragma once

#include "typedefs.h"


namespace gdl::tools {

class Vector3{
public:
	f32 x;
	f32 y;
	f32 z;

	Vector3();
	Vector3(f32 x, f32 y, f32 z);

	f32 mag();
	Vector3 nor();
	f32 dist(const Vector3& v);

	Vector3 operator+ (const Vector3& v);
	Vector3 operator- (const Vector3& v);
	Vector3 operator* (f32 v);
	Vector3 operator/ (f32 v);

	void operator+= (const Vector3& v);
	void operator-= (const Vector3& v);
	void operator*= (f32 v);
	void operator/= (f32 v);



};

}







