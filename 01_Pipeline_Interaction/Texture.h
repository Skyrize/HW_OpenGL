#pragma once
#include <GL/glew.h>
#include <string>

class Texture
{
private:
	GLuint texID = 0;
	GLuint rendererID = 0;
	std::string filePath = "";
	GLubyte* localBuffer = nullptr;
	GLint width, height, BPP = 0;
public:
	Texture(const std::string& path, GLuint texID);
	~Texture();

	void Bind() const;
	void Unbind() const;
public:
    std::string GetFilePath() const;

    GLint GetWidth() const;

    GLint GetHeight() const;

    GLint GetBPP() const;

	GLuint GetTexID() const;
	GLuint GetRendererID() const;

};


