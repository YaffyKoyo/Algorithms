#include "stdafx.h"
#include "StringManipulate.h"
#include <sstream>


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

	for (int i = 0; i < length / 2; i++)
	{
		if (_string[i] != _string[length - 1 - i]) { return false; }
	}
	return true;
}

/*
cracking the coding interview
Problem 1.1
Implement an algorithm to determine if a string has all unique characters.
*/
bool StringManipulate::isUniqueChars()
{
	if (_string.length() > 256) {
		return false;
	}
	bool char_set[256];
	for (int i = 0; i < 256; i++) {
		char_set[i] = false;
	}
	for (int i = 0; i < _string.length(); i++) {
		int val = (int)_string[i];
		if (char_set[val]) {
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

/*
cracking the coding interview
Problem 1.3
Given two strings, write a method to decide if one is a permutation of the other.
*/
bool StringManipulate::isPermutation(std::string str) {
	if (_string.length() != str.length()) return false;
	std::string sorted_string = _string;
	std::sort(sorted_string.begin(), sorted_string.end());

	std::string sorted_str = str;
	std::sort(sorted_str.begin(), sorted_str.end());

	if (sorted_str == sorted_string) {
		return true;
	}
	else
	{
		return false;
	}
}

/*
cracking the coding interview
Problem 1.5
Implement a method to perform basic string compression using the counts of
repeated characters.For example, the string aabcccccaaa would become
a2blc5a3.If the "compressed" string would not become smaller than the original
string, your method should return the original string.
*/
std::string StringManipulate::Compress() {
	std::string temp = "";
	int counter = 1;
	for (size_t i = 1; i < _string.length(); i++)
	{
		if (i == (_string.length() - 1)) {
			if (_string[i] != _string[i - 1]) {
				temp.push_back(_string[i - 1]);
				std::stringstream ss;
				ss << counter;
				std::string str = ss.str();
				temp.append(str);
				temp.push_back(_string[i]);
				temp.push_back('1');
			}
			else
			{
				temp.push_back(_string[i - 1]);
				std::stringstream ss;
				ss << counter + 1;
				std::string str = ss.str();
				temp.append(str);
			}
		}
		else if (_string[i] != _string[i - 1])
		{
			temp.push_back(_string[i - 1]);
			std::stringstream ss;
			ss << counter;
			std::string str = ss.str();
			temp.append(str);
			counter = 0;
		}
		counter++;
	}
	return temp;
}