#include <glm/glm.hpp>
#include <vector>
#include <iostream>

#include "../include/glad/glad.h"
#include "../include/GDL/engine/window.h"
#include "../include/GDL/game/camera.h"
#include "../include/GDL/engine/input.h"
#include "../include/GDL/engine/time.h"
#include "../include/GDL/graphics/shader.h"
#include "../include/GDL/graphics/mesh.h"
#include "../include/GDL/graphics/model.h"
#include "../include/GDL/tools/typedefs.h"
#include "../include/GDL/components/renderer.h"
#include "../include/GDL/components/transform.h"

#include "../include/GDL/assets/meshes/mesh_2d.h"




int main()
{
	gdl::engine::Window window(1280, 720, "Test");
    gdl::graphics::Shader shader("assets/shaders/def_vert.glsl", "assets/shaders/def_frag.glsl");



    gdl::Camera camera;
    camera.mode = gdl::CameraMode::PERSPECTIVE;

    camera.position.z = -10;



    gdl::graphics::Mesh cube1 = m_cube();
    gdl::graphics::Mesh cube2 = m_cube();

    gdl::graphics::Model model1(cube1);
    gdl::graphics::Model model2(cube2);




    gdl::components::Transform t1(&model1);
    gdl::components::Renderer r1(t1);


    gdl::components::Transform t2(&model2);
    gdl::components::Renderer r2(t2);

    t2.position.y = 3;

    t2.set_parent(&t1);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!window.should_close())
    {
        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        gdl::engine::Input::update(window.get_win());
        gdl::engine::Time::update();

        if(gdl::engine::Input::key_hold(GLFW_KEY_A)) t2.local_position.x += 2 * gdl::engine::Time::delta;
        if(gdl::engine::Input::mouse_hold(GLFW_MOUSE_BUTTON_1)) camera.position.z += 0.008;

        std::cout << "model1: "
        		  << t1.position.x << ", "
				  << t1.position.y << ", "
				  << t1.position.z << std::endl;

        std::cout << "model2: "
        		  << t2.position.x << ", "
				  << t2.position.y << ", "
				  << t2.position.z << std::endl << std::endl;

/*
        t1.local_rotation.x += gdl::engine::Time::delta * 45;
        t1.local_rotation.y += gdl::engine::Time::delta * 45;
        t1.local_rotation.z += gdl::engine::Time::delta * 45;
*/
        gdl::components::Transform::update(t1);
        gdl::components::Transform::update(t2);

        r1.draw(shader, camera);
        r2.draw(shader, camera);

        window.swap_buffers();
    }


    shader.kill();
    window.kill();

    return 0;
}



