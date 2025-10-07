// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "utils/FilePropertyStream.h"

int main()
{
    std::cout << "Hello World!\n";

    // If the file tests should be run...
    bool runFileTests = true;

    // Runs the file tests.
    if (runFileTests)
    {
        // Testing the file property system.
        std::string fileName = "test.txt";
        util::FilePropertyStream fps = util::FilePropertyStream(fileName);

        // File name.
        std::cout << std::endl;
        std::cout << "File: " << fileName << std::endl;

        // File exists.
        bool fpsExists = fps.fileInfo.fileExists();
        std::cout << "Exists: " << std::boolalpha << fpsExists << std::endl;

        // File size.
        std::cout << "Size: " << fps.fileInfo.getFileSizeInBytes() << std::endl;

        // If the file exists...
        if (fpsExists)
        {
            // Prints the contents.
            std::cout << "\nPrinting File Contents..." << std::endl;
            fps.printFileContents();
            // std::cout << std::endl;
            std::cout << "End of File Contents" << std::endl;
        }
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
