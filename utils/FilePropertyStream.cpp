#include "FilePropertyStream.h"

#include <istream>

struct header {
	uint32_t len;
	unsigned char type;
	char name[16];
};

// constructor
util::FilePropertyStream::FilePropertyStream()
{
}

// opens and gets the file
util::FilePropertyStream::FilePropertyStream(std::string filePath)
{
	// TODO: figure out how to read the file metadata

	// LPCSTR file = filePath.c_str();

	// DWORD c = GetFileAttributesA(file);	

	std::fstream file;
	std::string line;

	file.open("test.txt", std::ios::in);

	// until the file is finished being read.
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
}
