#pragma once
#include <string.h>
#include <algorithm>


class StringManipulate
{
private:
	std::string _string;

public:
	std::string getString() {
		return _string;
	}

	void setString(std::string str) {
		_string = str;
	}
	StringManipulate();
	inline StringManipulate(std::string string) { _string = string; }
	~StringManipulate();

	std::string FindNumInThree();
	bool isPalindrome();
	bool isUniqueChars();
	bool isPermutation(std::string str);
	std::string Compress();
};

