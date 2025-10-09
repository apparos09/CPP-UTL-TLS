/*
* References:
* https://www.oreilly.com/library/view/c-cookbook/0596007612/ch10s07.html
* https://learn.microsoft.com/en-us/windows/win32/fileio/file-attribute-constants
* https://en.cppreference.com/w/cpp/filesystem.html
* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesa
* https://cplusplus.com/doc/tutorial/files/
*/

// Reads information about a file. The package <filesystem> is only usable in C++17 and higher.

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


namespace util
{
	class FilePropertyStream
	{
	public:
		struct FileInfo
		{
		public:

			// Constructor
			FileInfo();

			// Constructor
			FileInfo(std::string filePath);

			// Returns 'true' if the file exists.
			bool fileExists();

			// Returns 'true' if the file path is valid.
			bool isFileAvailable();

			// Generates an open file object.
			std::fstream GenerateFileObject();

			// Gets the size of the file. Returns -1 if the file doesn't exist.
			int getFileSizeInBytes();

			// The file path.
			std::string filePath;

		private:
		protected:

		};

		// creates the object.
		FilePropertyStream();

		// opens the file
		FilePropertyStream(std::string filePath);

		// Saves the file and reads its contents.
		void printFileContents(std::string filePath);
	
		// Prints the file's contents.
		void printFileContents();

		// The file info.
		FileInfo fileInfo;

	private:

	protected:
	};
}