#include "FilePropertyStream.h"

#include <istream>

struct header {
	uint32_t len;
	unsigned char type;
	char name[16];
};

// FilePropertyStream - FileInfo Struct
util::FilePropertyStream::FileInfo::FileInfo()
{
	filePath = "";
}

// FilePropertyStream - FileInfo Struct
util::FilePropertyStream::FileInfo::FileInfo(std::string filePath)
{
	this->filePath = filePath;
}

// Returns 'true' if the file exists.
bool util::FilePropertyStream::FileInfo::fileExists()
{
	// File path doesn't exist.
	if (filePath == "")
	{
		return false;
	}

	// Checks if the file exists and returns the result.
	bool result = std::filesystem::exists(filePath);
	return result;
}

// Returns 'true' if the file is available, false if it is not.
bool util::FilePropertyStream::FileInfo::isFileAvailable()
{
	// The file path is blank.
	if (filePath == "")
	{
		return false;
	}

	// Tries to open the file.
	std::fstream file;
	file.open(filePath);

	// Gets the result for the file being open.
	bool result = file.is_open();

	// Closes the file.
	file.close();

	// Returns the result.
	return result;
}

// Generates an object file using the provided file path.
std::fstream util::FilePropertyStream::FileInfo::GenerateFileObject()
{
	// If the file's available.
	if (isFileAvailable())
	{
		// File
		std::fstream file;

		// Read/Write
		file.open(filePath);

		// Return
		return file;
	}
	else
	{
		// Error message.
		std::cout << "Error: File could not be opened. Returned null object." << std::endl;

		// Returned empty.
		return std::fstream();
	}
}

// Gets the file size. Returns -1 if the file doesn't exist.
int util::FilePropertyStream::FileInfo::getFileSizeInBytes()
{
	// Checks if the file exists.
	if (fileExists()) // Exists.
	{
		int size = std::filesystem::file_size(filePath);
		return size;

	}
	else // Does not exist.
	{
		return -1;
	}
}



// FilePropertyStream
// constructor
util::FilePropertyStream::FilePropertyStream()
{
	fileInfo = FileInfo();
}

// opens and gets the file
util::FilePropertyStream::FilePropertyStream(std::string filePath)
{
	// Opens the file.
	fileInfo = FileInfo(filePath);
}

// Saves the provided file and reads the file contents.
void util::FilePropertyStream::printFileContents(std::string filePath)
{
	// Opens the file.
	fileInfo = filePath;

	// Goes to print the file contents.
	printFileContents();
}

// Prints the file contents.
void util::FilePropertyStream::printFileContents()
{
	// If the file is available.
	if(fileInfo.isFileAvailable())
	{
		// Generates the file object.
		std::fstream file = fileInfo.GenerateFileObject();

		// Line from the file.
		std::string line;

		// Until the file is finished being read, print lines.
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
		}

		// Closes the file.
		file.close();
	}
	else
	{
		std::cout << "File could not be opened." << std::endl;
	}

}


