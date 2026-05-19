// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "utils/Utils.h"
#include "utils/FilePropertyStream.h"

int main()
{
    std::cout << "Hello World!\n";

    // If string tests should be run.
    bool runStringTests = true;

    // Runs the string tests.
    if (runStringTests)
    {
        std::cout << std::endl;

        // Testing stringContains (std::string)
        std::string testStr = "ABCD";
        std::string testStrSearch = "E";

        std::cout << "[std::string] stringContains(" + testStr + ", " << testStrSearch << ") = " 
            << std::boolalpha << util::stringContains(testStr, testStrSearch);

        std::cout << std::endl;

        // Testing stringContains (std::wstring)
        std::wstring testWStr = L"FGHI";
        std::wstring testWStrSearch = L"H";

        std::wcout << L"[std::wstring] stringContains(" + testWStr + L", " << testWStrSearch << L") = "
            << std::boolalpha << util::stringContains(testWStr, testWStrSearch);

        std::cout << std::endl;

        // Test substring counts.
        std::string substrCnt01 = "Test test TEST tEst... This is a test for a tester.";
        std::wstring substrCnt02 = L"Test test TEST tEsT... This is a test for a tester.";

        std::cout << std::endl;
        std::cout << "substrCount(\"" << substrCnt01 << "\", \"test\", false) = " << util::substringCount(substrCnt01, "test", false) << std::endl;
        std::wcout << "substrCount(\"" << substrCnt02 << "\", \"test\", true) = " << util::substringCount(substrCnt01, "test", true) << std::endl;
        std::cout << std::endl;

        // Testing the trim functions.
        std::string trimStr01 = "   trim01   ";
        std::string trimStr02 = "trim02  ";
        std::string trimStr03 = "   trim03";
        std::string trimStr04 = " trim04   ";
        std::string trimStr05 = "   trim05 ";
        std::string trimStr06 = "\ttrim06\t";
        std::wstring trimStr07 = L"    trim07    ";
        std::wstring trimStr08 = L"  trim08  ";
        std::string trimStr09 = "AaAtrim09AaA";
        std::string trimStr10 = "AaAtrim10AaA";

        std::cout << std::endl;
        std::cout << "trimString(\"" << trimStr01 << "\") = " << util::trimString(trimStr01) << std::endl;
        std::cout << "trimString(\"" << trimStr02 << "\") = " << util::trimString(trimStr02, " ") << std::endl;
        std::cout << "trimString(\"" << trimStr03 << "\") = " << util::trimString(trimStr03) << std::endl;
        std::cout << "trimString(\"" << trimStr04 << "\") = " << util::trimString(trimStr04) << std::endl;
        std::cout << "trimString(\"" << trimStr05 << "\") = " << util::trimString(trimStr05, " ") << std::endl;
        std::cout << "trimString(\"" << trimStr06 << "\") = " << util::trimString(trimStr06, "\t") << std::endl;
        std::wcout << "trimString(\"" << trimStr07 << "\") = " << util::trimString(trimStr07) << std::endl;
        std::wcout << "trimString(\"" << trimStr08 << "\") = " << util::trimString(trimStr08) << std::endl;
        std::cout << "trimString(\"" << trimStr09 << "\", \"A\", false) = " << util::trimString(trimStr09, "A", false) << std::endl;
        std::cout << "trimString(\"" << trimStr10 << "\", \"A\", true) = " << util::trimString(trimStr10, "A", true) << std::endl;

        std::cout << std::endl;
    }

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
    
    std::cout << std::endl;

    system("pause");
    return 0;
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
