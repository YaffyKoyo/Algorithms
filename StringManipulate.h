#pragma once
#include <string.h>


class StringManipulate
{
private:
	std::string _string;

public:
	StringManipulate();
	inline StringManipulate(std::string string) { _string = string; }
	~StringManipulate();

	std::string FindNumInThree();
};

