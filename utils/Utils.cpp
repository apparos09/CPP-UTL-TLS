/*
 * Date: 05/03/2020
	* Last Updated: 04/18/2026
 * References:
	* https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
	* http://www.cplusplus.com/reference/string/string/substr/
	* http://www.cplusplus.com/reference/string/string/erase/
	* https://en.cppreference.com/w/cpp/language/inline.html
	* https://www.geeksforgeeks.org/cpp/inline-functions-cpp/
	* https://www.geeksforgeeks.org/cpp/how-to-split-string-by-delimiter-in-cpp/
	* https://en.cppreference.com/cpp/string/basic_string
*/

#include "Utils.h"
#include "math/LargeInt.h"
#include "math/Quaternion.h"

#include <cmath>
#include <math.h>
#include <sstream>
#include <fstream>
#include <stack>

/// STRING AND GENERAL FUNCTIONS //////////////////////////////////////////////////////
// converts a whole string to lowercase
std::string util::toLower(std::string str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::string strL; // temporary string
	strL.assign(str); // copies original string

	for (int i = 0; i < strL.length(); i++)
	{
		strL.at(i) = tolower(strL.at(i)); // converts each 'char' to its lowercase version if applicable
	}

	return strL;
}

// converts a whole wstring to lowercase
std::wstring util::toLower(std::wstring str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::wstring strL; // temporary string
	strL.assign(str); // copies original string

	for (int i = 0; i < strL.length(); i++)
	{
		strL.at(i) = tolower(strL.at(i)); // converts each 'char' to its lowercase version if applicable
	}

	return strL;
}

// converts a whole string to uppercase
std::string util::toUpper(std::string str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::string strL; // temporary string
	strL.assign(str); // copies original string

	for (int i = 0; i < strL.length(); i++)
	{
		strL.at(i) = toupper(strL.at(i)); // converts each 'char' to its uppercase version if applicable
	}

	return strL;
}

// converts a whole wstring to uppercase
std::wstring util::toUpper(std::wstring str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::wstring strL; // temporary string
	strL.assign(str); // copies original string

	for (int i = 0; i < strL.length(); i++)
	{
		strL.at(i) = toupper(strL.at(i)); // converts each 'char' to its uppercase version if applicable
	}

	return strL;
}

// capitalizes a string.
std::string util::captialize(std::string str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::string strL; // temporary string
	strL.assign(str); // copies original string

	str = toLower(str); // makes the string all lowercase
	str.at(0) = toupper(str.at(0)); // capitalizes the first letter

	return strL;
}

// capitalizes a wstring.
std::wstring util::captialize(std::wstring str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::wstring strL; // temporary string
	strL.assign(str); // copies original string

	str = toLower(str); // makes the string all lowercase
	str.at(0) = toupper(str.at(0)); // capitalizes the first letter

	return strL;
}

// checks if two strings are equal, ignoring case differences.
bool util::equalsIgnoreCase(std::string str1, std::string str2)
{
	// making both strings lowercase
	str1 = toLower(str1);
	str2 = toLower(str2);
	return str1 == str2; // returning whether the two are equal
}

// checks if two strings are equal, ignoring case differences.
bool util::equalsIgnoreCase(std::wstring str1, std::wstring str2)
{
	// making both strings lowercase
	str1 = toLower(str1);
	str2 = toLower(str2);
	return str1 == str2; // returning whether the two are equal
}

// checks if string 2 can be found in string 1.
bool util::stringContains(std::string str1, std::string str2)
{
	return str1.find(str2) != std::string::npos;
}

// checks if wstring 2 can be found in wstring 1.
bool util::stringContains(std::wstring str1, std::wstring str2)
{
	return str1.find(str2) != std::wstring::npos;
}

// replaces every instance of a set of characters in a string with another set of characters.
std::string util::replaceSubstring(std::string str, std::string oldSubstr, std::string newSubstr, bool ignoreCase)
{
	unsigned int index; // the index of the most recently found oldSubstr

	// first set is if ignoreCase is false, second set is if ignoreCase is true.
	while ((ignoreCase == false && str.find(oldSubstr) != std::string::npos) || 
		   (ignoreCase == true && util::toLower(str).find(util::toLower(oldSubstr)) != std::string::npos))
	{
		// checks if case sensitivity was requested.
		index = (ignoreCase) ? index = util::toLower(str).find(util::toLower(oldSubstr)) : index = str.find(oldSubstr);

		str.replace(index, oldSubstr.length(), newSubstr); // replaces the old string with the new string.
	}

	return str;
}

// replaces every instance of a set of wide characters in a wstring with another set of wide characters.
std::wstring util::replaceSubstring(std::wstring str, std::wstring oldSubstr, std::wstring newSubstr, bool ignoreCase)
{
	unsigned int index; // the index of the most recently found oldSubstr

	// first set is if ignoreCase is false, second set is if ignoreCase is true.
	while ((ignoreCase == false && str.find(oldSubstr) != std::string::npos) ||
		(ignoreCase == true && util::toLower(str).find(util::toLower(oldSubstr)) != std::string::npos))
	{
		// checks if case sensitivity was requested.
		index = (ignoreCase) ? index = util::toLower(str).find(util::toLower(oldSubstr)) : index = str.find(oldSubstr);

		str.replace(index, oldSubstr.length(), newSubstr); // replaces the old string with the new string.
	}

	return str;
}

// splits a string into a vector of strings
std::vector<std::string> util::splitString(const std::string str, const std::string delimiter, const bool includeBlanks)
{
	// the string vector
	std::vector<std::string> vec;

	// copies the string
	std::string strCpy = str;

	// while there are still instances of the delimiter
	while (strCpy.find(delimiter) != std::string::npos)
	{
		// gets the index
		int index = strCpy.find(delimiter);

		// gets the section of the string.
		std::string temp = strCpy.substr(0, index);

		// if blanks are included, or if blanks are not included but the string is not blank, it gets added to the list
		if ((includeBlanks) || (!includeBlanks && temp != ""))
		{
			// pushes back string and removes it from the strCpy
			vec.push_back(temp);
		}
		
		// this works by deleting a range of characters upto but not including the last character [first, last)
		// as such, the index of the delimiter must be increased the amount of characters in the delimiter.
		strCpy.erase(0, index + delimiter.size()); // erases the string
	}

	// if there's anything left in the string, then that's added as the final element in the vector.
	if (!strCpy.empty())
	{
		vec.push_back(strCpy);
	}

	return vec;
}

// splits a wstring into a vector based on the provided delimiter (seperator).
std::vector<std::wstring> util::splitString(const std::wstring str, const std::wstring delimiter, const bool includeBlanks)
{
	// the wstring vector
	std::vector<std::wstring> vec;

	// copies the wstring
	std::wstring strCpy = str;

	// while there are still instances of the delimiter
	while (strCpy.find(delimiter) != std::string::npos)
	{
		// gets the index
		int index = strCpy.find(delimiter);

		// gets the section of the string.
		std::wstring temp = strCpy.substr(0, index);

		// if blanks are included, or if blanks are not included but the string is not blank, it gets added to the list
		if ((includeBlanks) || (!includeBlanks && temp != L""))
		{
			// pushes back string and removes it from the strCpy
			vec.push_back(temp);
		}

		// this works by deleting a range of characters upto but not including the last character [first, last)
		// as such, the index of the delimiter must be increased the amount of characters in the delimiter.
		strCpy.erase(0, index + delimiter.size()); // erases the string
	}

	// if there's anything left in the string, then that's added as the final element in the vector.
	if (!strCpy.empty())
	{
		vec.push_back(strCpy);
	}

	return vec;
}

// checks if a string is an integer.
bool util::isInt(std::string str)
{
	int strInt; // gets the string as an int.
	std::stringstream ss(str); // creates a string stream for converting the string to an integer.

	ss >> strInt; // puts the string stream into the integer. If non-int values exist, then the int is truncated.

	return std::to_string(strInt) == str; // returns 'true' if all values were carried over from the string.
}

// checks if a wstring is an integer.
bool util::isInt(std::wstring str)
{
	int strInt; // gets the string as an int.
	std::wstringstream ss(str); // creates a wide string stream for converting the wstring to an integer.

	ss >> strInt; // puts the string stream into the integer. If non-int values exist, then the int is truncated.

	return std::to_wstring(strInt) == str; // returns 'true' if all values were carried over from the wstring.
}

// checks if a string is a decimal number (specifically a double).
bool util::isDecimal(std::string str)
{
	double strDbl; // gets the string as an float
	std::stringstream ss(str); // creates a string stream for converting the string to an integer.

	ss >> strDbl; // puts the string stream into the double. If non-int values exist, then the doubleis truncated.

	return std::to_string(strDbl) == str; // returns 'true' if all values were carried over from the string.
}

// checks if a wstring is a decimal number (specifically a double).
bool util::isDecimal(std::wstring str)
{
	double strDbl; // gets the string as an float
	std::wstringstream ss(str); // creates a string stream for converting the string to an integer.

	ss >> strDbl; // puts the string stream into the double. If non-int values exist, then the doubleis truncated.

	return std::to_wstring(strDbl) == str; // returns 'true' if all values were carried over from the wstring.
}

// checks to see if a string is a number. IsInt or IsDecimal should be used instead.
bool util::isNum(std::string str)
{
	std::string arr[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	// Checks each index of the wstring, checking if it's a whole, numeric value.
	for (int x = 0; x < str.length(); x++) {
		for (int y = 0; y < 10; y++) {
			if (str.substr(x, 1) == arr[y]) {
				break;
			}
			else if (y == 9) {
				return false;
			}
		}
	}
	return true;
}

// checks to see if a wstring is a number. IsInt or IsDecimal should be used instead.
bool util::isNum(std::wstring str)
{
	std::wstring arr[10] = { L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9" };

	// Checks each index of the wstring, checking if it's a whole, numeric value.
	for (int x = 0; x < str.length(); x++) {
		for (int y = 0; y < 10; y++) {
			if (str.substr(x, 1) == arr[y]) {
				break;
			}
			else if (y == 9) {
				return false;
			}
		}
	}
	return true;
}

// string to integer
int util::stringToInt(const std::string& str) 
{ 
	return convertString<int>(str); 
}

// wstring to integer
int util::stringToInt(const std::wstring& str)
{
	return convertString<int>(str);
}

// string to short
short util::stringToShort(const std::string& str)
{ 
	return convertString<short>(str); 
}

// wstring to short
short util::stringToShort(const std::wstring& str)
{
	return convertString<short>(str);
}

// string to long
long util::stringToLong(const std::string& str) 
{ 
	return convertString<long>(str);
}

// wstring to long
long util::stringToLong(const std::wstring& str)
{
	return convertString<long>(str);
}

// string to double
double util::stringToDouble(const std::string& str) 
{ 
	return convertString<double>(str); 
}

// wstring to double
double util::stringToDouble(const std::wstring& str)
{
	return convertString<double>(str);
}

// string to float
float util::stringToFloat(const std::string& str)
{
	return convertString<float>(str);
}

// string to float
float util::stringToFloat(const std::wstring& str)
{
	return convertString<float>(str);
}

// converts a double to a string.
std::string util::doubleToString(double value)
{
	// if converted using the standard to_string, extra, unnecesscary zero digits are included.
	// this fixes that problem.
	std::ostringstream out;
	out << value;
	return out.str();
}

// converts a double to a wstring.
std::wstring util::doubleToWString(double value)
{
	// if converted using the standard to_string, extra, unnecesscary zero digits are included.
	// this fixes that problem.
	std::wostringstream out;
	out << value;
	return out.str();
}

// converts a float to a string.
std::string util::floatToString(float value)
{
	// if converted using the standard to_string, extra, unnecesscary zero digits are included.
	// this fixes that problem.
	std::ostringstream out;
	out << value;
	return out.str();
}

// converts a float to a wstring.
std::wstring util::floatToWString(float value)
{
	// if converted using the standard to_wstring, extra, unnecesscary zero digits are included.
	// this fixes that problem.
	std::wostringstream out;
	out << value;
	return out.str();
}

// fills in zeros for integers converted to strings.
std::string util::zeroFill(int num, const unsigned int LENGTH)
{
	// note: string.size() and string.length() do the same thing.

	// empty string
	if (LENGTH == 0)
		return std::string("");

	// converts the number to a string.
	std::string numString = std::to_string(num);

	// temporary string to get the zero fill value.
	std::string temp = "";

	// the string's requested length is less than that of the number's itself.
	if (LENGTH < numString.length())
	{
		temp = numString.substr(numString.length() - LENGTH);
	}
	else
	{
		temp = numString;

		// filling with zeroes.
		while (temp.size() < LENGTH)
			temp = "0" + temp;
	}

	return temp;
}

// fills in zeros for integers converted to wstrings.
std::wstring util::zeroFillW(int num, const unsigned int LENGTH)
{
	// note: wstring.size() and wstring.length() do the same thing.
	
	// empty wstring
	if (LENGTH == 0)
		return std::wstring(L"");

	// converts the number to a string.
	std::wstring numString = std::to_wstring(num);

	// temporary string to get the zero fill value.
	std::wstring temp = L"";

	// the string's requested length is less than that of the number's itself.
	if (LENGTH < numString.length())
	{
		temp = numString.substr(numString.length() - LENGTH);
	}
	else
	{
		temp = numString;

		// filling with zeroes.
		while (temp.size() < LENGTH)
			temp = L"0" + temp;
	}

	return temp;
}

// returns 'true' if the file can be opened and read from.
bool util::fileAccessible(const std::string& filePath)
{
	std::ifstream file(filePath, std::ios::in); // the file
	bool found;

	// if !file is true, then the file couldn't be opened. If it is false, then the file can be accessed.
	found = !file;
	file.close();

	// returns the opposite as 'found' since it's showing if the file does exist.
	return !found;
}

// returns 'true' if the file can be opened and read from.
bool util::fileAccessible(const std::wstring& filePath)
{
	std::wifstream file(filePath, std::ios::in); // the file
	bool found;

	// if !file is true, then the file couldn't be opened. If it is false, then the file can be accessed.
	found = !file;
	file.close();

	// returns the opposite as 'found' since it's showing if the file does exist.
	return !found;
}
