/*
* References:
* https://www.oreilly.com/library/view/c-cookbook/0596007612/ch10s07.html
* https://learn.microsoft.com/en-us/windows/win32/fileio/file-attribute-constants
* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesa
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>

// causes error when included.
// #include <fileapi.h>

// #include <sys/stat.h>


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
		// struct stat file;

	protected:

	};
}