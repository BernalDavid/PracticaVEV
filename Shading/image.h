// -*-C++-*-

#pragma once

#include <string>
#include <vector>
#include <map>
#include <GL/glew.h>
#include <GL/freeglut.h>

// this class acts as a manager also

class Image {
public:

	void print() const;

	const char *getName() const;
	const std::string &getNameString() const;
	int getWidth() const;
	int getHeight() const;
	int getComponents() const;
	size_t getSize() const;
	const unsigned char *getData() const;
	int saveJPG(const std::string & fname) const;

	friend class ImageManager;

private:
	Image(const std::string &fname, bool flip = true);
	~Image();
	Image(const Image &);
	Image & operator =(const Image &);
	void load(bool flip);

	std::string m_fileName; // The image path
	int m_width;      // (must be power of 2)
	int m_height;     // (must be power of 2)
	int m_components;
	size_t m_size;
	std::vector<unsigned char> m_data;
};
