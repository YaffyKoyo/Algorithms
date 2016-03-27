#include "stdafx.h"
#include "StringManipulate.h"


StringManipulate::StringManipulate()
{
}


StringManipulate::~StringManipulate()
{
}

std::string StringManipulate::FindNumInThree()
{
	std::string f = "";
	int count = 0;

	for (int i = 0; i < _string.length(); i++) {
		if ('0' <= _string[i] && '9' >= _string[i]) {
			if (count % 3 == 0 && count>0) {
				f = f + '-' + _string[i];
			}
			else {
				f = f + _string[i];
			}
			count++;
		}
	}

	if (f[f.length() - 2] == '-') {
		char temp = f[f.length() - 2];
		f[f.length() - 2] = f[f.length() - 3];
		f[f.length() - 3] = temp;
	}
	return f;


}

bool StringManipulate::isPalindrome()
{
	int length = _string.length();

	for (int i = 0; i < length/2; i++)
	{	
		if (_string[i] != _string[length - 1 - i]) { return false; }
	}
	return true;
}
