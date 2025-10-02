#include "../../../include/GDL/engine/window.h"
#include "../../../include/glad/glad.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}


namespace gdl::engine {



Window::Window(u16 w, u16 h, const str& t) : width(w), height(h), title(t){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	#ifdef __APPLE__
	    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	window = glfwCreateWindow((i32)width, (i32)height, title.c_str(), NULL, NULL);

	if (window == NULL) {
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, framebuffer_size_callback);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		exit(-2);
	}
}

GLFWwindow* Window::get_win(){
	return window;
}

bool Window::should_close(){
	return glfwWindowShouldClose(window);
}

void Window::kill(){
	glfwTerminate();
}

void Window::swap_buffers(){
	glfwSwapBuffers(window);
}

u16 Window::w(){
	return width;
}

u16 Window::h(){
	return height;
}


}








