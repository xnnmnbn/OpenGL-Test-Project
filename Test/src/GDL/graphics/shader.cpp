#include "../../../include/GDL/graphics/shader.h"
#include "../../../include/glad/glad.h"


namespace gdl {


Shader::Shader(const str& vert_path, const str& frag_path){
	id = 0;

	std::ifstream vert_file(vert_path);

	if(!vert_file.is_open()){ exit(-3); }
	str  vert_str((std::istreambuf_iterator<char>(vert_file)), std::istreambuf_iterator<char>());
	const char* vert_src = vert_str.c_str();

	vert_file.close();

	std::ifstream frag_file(frag_path);

	if(!frag_file.is_open()){ exit(-4); }
	str  frag_str((std::istreambuf_iterator<char>(frag_file)), std::istreambuf_iterator<char>());
	const char* frag_src = frag_str.c_str();

	frag_file.close();

	u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vert_src, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		exit(-5);
	}

	u32 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &frag_src, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success){
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
	}

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use(){
	glUseProgram(id);
}

void Shader::kill(){
	glDeleteProgram(id);
}

void Shader::setInt(const std::string& name, i32 value){
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, f32 value){
	glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}
void Shader::setBool(const std::string& name, bool value){
	glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}
void Shader::setVec2(const std::string& name, const glm::vec2& value){
	glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}
void Shader::setVec3(const std::string& name, const glm::vec3& value){
	glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}
void Shader::setVec4(const std::string& name, const glm::vec4& value){
	glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}
void Shader::setMat4(const std::string& name, const glm::mat4& value){
	glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &value[0][0]);
}


}








