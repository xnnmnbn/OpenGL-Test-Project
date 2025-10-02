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

//inline static gdl::graphics::Mesh sq = m_square();







