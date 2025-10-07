#include "../../../include/GDL/engine/time.h"
#include <GLFW/glfw3.h>

#include <iostream>

f32 last = 0;

namespace gdl {

f32 Time::time;
f32 Time::delta;


void Time::update(){
	Time::time = glfwGetTime();
	Time::delta = Time::time - last;

	last = Time::time;
}

}

