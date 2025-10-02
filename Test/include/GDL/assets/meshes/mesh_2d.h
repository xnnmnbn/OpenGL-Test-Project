#pragma once

#include "../../graphics/mesh.h"


inline static gdl::graphics::Mesh m_square(){
	static std::vector<gdl::graphics::Vertex> vert;

    vert.push_back({ gdl::tools::Vector3(-0.5f,  0.5f, 0.0f) });
	vert.push_back({ gdl::tools::Vector3( 0.5f,  0.5f, 0.0f) });
	vert.push_back({ gdl::tools::Vector3( 0.5f, -0.5f, 0.0f) });
	vert.push_back({ gdl::tools::Vector3(-0.5f, -0.5f, 0.0f) });

	static std::vector<u32> idx = {
		0, 1, 2,
		2, 3, 0
	};

	return gdl::graphics::Mesh(vert, idx);
}

inline static gdl::graphics::Mesh m_cube(){
	static std::vector<gdl::graphics::Vertex> vert;

    vert.push_back({ gdl::tools::Vector3(-0.5f,  0.5f,  0.5f) });
	vert.push_back({ gdl::tools::Vector3( 0.5f,  0.5f,  0.5f) });
	vert.push_back({ gdl::tools::Vector3( 0.5f, -0.5f,  0.5f) });
	vert.push_back({ gdl::tools::Vector3(-0.5f, -0.5f,  0.5f) });

    vert.push_back({ gdl::tools::Vector3(-0.5f,  0.5f, -0.5f) });
	vert.push_back({ gdl::tools::Vector3( 0.5f,  0.5f, -0.5f) });
	vert.push_back({ gdl::tools::Vector3( 0.5f, -0.5f, -0.5f) });
	vert.push_back({ gdl::tools::Vector3(-0.5f, -0.5f, -0.5f) });

	static std::vector<u32> idx = {
		0, 1, 2, //front
		2, 3, 0,

		4, 5, 6, //back
		6, 7, 4,

		0, 4, 7, //left
		7, 3, 0,

		1, 5, 6, //right
		6, 2, 1,

		0, 1, 4, //up
		4, 5, 1,

		3, 2, 7, //down
		7, 6, 2

	};

	return gdl::graphics::Mesh(vert, idx);
}







