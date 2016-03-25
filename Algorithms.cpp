// algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

void printNum(string);

int main()
{
	cout << "hello world!" << endl;

	string original = "2k34lj233jlkj;kjh5lk4l34j5li3uh5liu3i5uhluhluhuuhi167lk8hl3h76457u67hli82uhli86l24h5iu224";
	printNum(original);
	system("pause");
	return 0;
}

void printNum(string o) {

	string f = "";
	int count = 0;

	for (int i = 0; i < o.length(); i++) {
		if ('0' <= o[i] && '9' >= o[i]) {
			if (count % 3 == 0 && count>0) {
				f = f + '-' + o[i];
			}
			else {
				f = f + o[i];
			}
			count++;
		}
	}

	if (f[f.length() - 2] == '-') {
		char temp = f[f.length() - 2];
		f[f.length() - 2] = f[f.length() - 3];
		f[f.length() - 3] = temp;
	}

	cout << f << endl;
}


