/*
* References:
* https://www.oreilly.com/library/view/c-cookbook/0596007612/ch10s07.html
*/

#pragma once
#include <iostream>
#include <string>
#include <sys/stat.h>

namespace util
{
	class FilePropertyStream
	{
	public:
		// creates the object.
		FilePropertyStream();

		// opens the file
		FilePropertyStream(std::string filePath);
	
	private:
		struct stat file;

	protected:

	};
}