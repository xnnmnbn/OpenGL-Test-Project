#pragma once

#include <fstream>
#include <string>
#include <glm/glm.hpp>

#include "../tools/typedefs.h"


namespace gdl::graphics {


class Shader{
private:
	u32 id;

public:
	Shader(const str& vert_path, const str& frag_path);

	void use();
	void kill();

	void setInt(const std::string& name, i32 value);
	void setFloat(const std::string& name, f32 value);
	void setBool(const std::string& name, bool value);
	void setVec2(const std::string& name, const glm::vec2& value);
	void setVec3(const std::string& name, const glm::vec3& value);
	void setVec4(const std::string& name, const glm::vec4& value);
	void setMat4(const std::string& name, const glm::mat4& value);
};




}



