// algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringManipulate.h"
#include "TreeManipulate.h"
#include <unordered_map>
using namespace std;

struct BSTnode
{
	int data;
	BSTnode *left, *right;
};

int main();

void NullTerminalStringReverse(char * str);

void replaceSpaces(char str[], int length);

BSTnode *CreateBST(BSTnode*, int);
void Inorder(BSTnode*);

bool isAnagram(string str1, string str2);

void insertionSort(vector<int> ar);

void insertionSort(int ar_size, int * ar);

int nonContiguousSum(int size, int * array);

int contiguousSum(int size, int * array);

int vectorMaxSum(int ar_length, vector<int*> intVector);

void quickSort(vector<int>& A, int p, int q);

int partition(vector<int>& A, int p, int q);


int main()
{
	//cout << "hello world!" << endl;
	StringManipulate sm("123456");
	StringManipulate cm("ababbbbaddddccaaa");
	cout << sm.isPermutation("645322") << endl;

	char keke[20] = "a b cd ef";
	char* kePtr = keke;
	NullTerminalStringReverse(kePtr);
	replaceSpaces(keke, 9);
	cout << keke << endl;
	cout << cm.Compress() << endl;



	if (sm.isUniqueChars()) {
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}


	//Binary tree implement
	/*	BSTnode* bstNode = NULL;
		srand(time(NULL));

		TreeManipulate *tm = new TreeManipulate();


		int a[10];
		for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
			a[i] = i;
		}

		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			int num = rand() % (sizeof(a) / sizeof(a[0])-i) + i;
			std::swap(a[i], a[num]);
		}


		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			bstNode = CreateBST(bstNode, a[i]);
			tm->Add(a[i]);
			cout << a[i]<<" ";
		}
		cout << endl;


		Inorder(bstNode);
		cout << endl;
		tm->InOrderTraversal(tm->root);
		cout << endl;
		tm->PreOrderTraversal(tm->root);
		cout << endl;
		tm->PostOrderTraversal(tm->root);*/

	char* string1 = "string1";
	char string2[] = "string2";
	cout << string1 << endl;

//test.............for hashMap
	/*int num;
	cout << "type: ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		string temp;
		unordered_map<char, int> tempHash;
		cin >> temp;
		for (int n = 0; n < temp.length(); n++) {
			auto search = tempHash.find(temp[n]);
			if (search!=tempHash.end()) {
				tempHash[temp[n]]++;
			}
			else {
				tempHash[temp[n]] = 1;
			}
		}

		for (auto it = tempHash.begin();it!=tempHash.end();++it)
		{
			cout << " " << it->first << ":" << it->second;
		}
		cout << endl;

	}
*/

//test for sherlock and anagram
	/*int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string temp;
		cin >> temp;
		int length = temp.length();
		int sum = 0;
		for (int subLength = 1; subLength < length;subLength++) {
			vector<string> subStrings;
			for (int n=0;n<length-subLength+1;n++)
			{
				subStrings.push_back(temp.substr(n, subLength));
			}
			cout << "sub string length = " << subLength <<":"<< endl;
			for (auto it = subStrings.begin();it!=subStrings.end()-1;++it)
			{
				for (auto itNext = it+1;itNext!=subStrings.end();++itNext)
				{
					if (isAnagram(*it,*itNext))
					{
						sum++;
					}
				}
			}
			cout << endl;

		}
		cout << sum << endl;

	}*/

//test for insertion sort part1
	/*vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++) {
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp);
	}

	insertionSort(_ar);*/


//test for insertion sort part2
	/*int _ar_size;
	cin >> _ar_size;
	int *_ar;
	_ar = new int[_ar_size];
	int _ar_i;
	for (_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
		cin >> _ar[_ar_i];
	}


	insertionSort(_ar_size, _ar);

	delete _ar;*/

//test for maxsubarray
	/*int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			int n, *array;
			cin >> n;
			array = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> array[j];
			}
			cout << contiguousSum(n, array) << endl;
		}*/

//test for quicksort

	vector<int> A = { 6,10,13,5,8,3,2,25,4,11 };
	int p = 0;
	int q = 10;

	cout << "======Original=======" << endl;
	for (auto e : A)
		cout << e << " ";
	cout << endl;

	quickSort(A, p, q);

	cout << "======Sorted=======" << endl;
	for (auto e : A)
		cout << e << " ";
	cout << endl;

	system("pause");
	return 0;
}

/*
	cracking the coding interview
	Problem 1.2
	Implement a function void reverse(char* str) in C/C++ which reverses a null-terminated string
*/
void NullTerminalStringReverse(char* str) {
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	int mid = length / 2;
	for (int i = 0; i < mid; i++) {
		char k;
		k = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = k;
	}
}
/*
	cracking the coding interview
	Problem 1.4
	replace space with '%20' in a string
*/
void replaceSpaces(char str[], int length) {
	int i = 0;
	int spaceCount = 0;
	for (int n = 0; n < length; n++) {
		if (str[n] == ' ') spaceCount++;
	}

	int finalLength = length + spaceCount * 2;
	str[finalLength] = '\0';
	for (size_t i = length - 1; i > 0; i--)
	{
		if (str[i] == ' ')
		{
			str[finalLength - 1] = '0';
			str[finalLength - 2] = '2';
			str[finalLength - 3] = '%';
			finalLength -= 3;
		}
		else
		{
			str[finalLength - 1] = str[i];
			finalLength -= 1;
		}
	}

}

BSTnode * CreateBST(BSTnode* root, int element)
{
	if (root == NULL) {
		root = new BSTnode;
		root->data = element;
		root->left = root->right = NULL;
		return root;
	}
	else
	{
		if (element < root->data)
			root->left = CreateBST(root->left, element);
		else
			if (element > root->data)
				root->right = CreateBST(root->right, element);
			else
				printf(" Duplicate Element !! Not Allowed !!!");

		return(root);

	}
}

void Inorder(BSTnode *root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf(" %d ", root->data);
		Inorder(root->right);
	}
}

bool isAnagram(string str1, string str2) {
	bool flag = true;
	if (str1.length() != str2.length())
	{
		return false;
	}
	else
	{
		int letters1[26];
		int letters2[26];
		for (int i = 0; i < 26; i++)
		{
			letters1[i] = 0;
			letters2[i] = 0;
		}
		for (int i = 0; i < str1.length(); i++)
		{
			letters1[str1[i] - 'a']++;
			letters2[str2[i] - 'a']++;
		}
		for (size_t i = 0; i < 26; i++)
		{
			if (letters1[i] != letters2[i])
			{
				flag = false;
			}
		}
		return flag;
	}
}

void insertionSort(vector <int>  ar) {
	int temp = ar.back();
	for (auto it = ar.rbegin(); it != ar.rend(); ++it) {
		if (*(it + 1) > temp) {
			*it = *(it + 1);
			for (auto jt = ar.begin(); jt != ar.end(); ++jt) {
				cout << *jt << ' ';
			}
			cout << endl;
		}
		else {
			*it = temp;
			break;
		}
	}
	for (auto jt = ar.begin(); jt != ar.end(); ++jt) {
		cout << *jt << ' ';
	}
}

void insertionSort(int ar_size, int* ar) {
	int count_i = 0;
	for (int i = 1; i < ar_size; ++i)
	{
		int temp = ar[i];
		int count = 0;
		for (int j = i; j > 0; --j)
		{
			count++;
			if (ar[j - 1] > temp)
			{
				ar[j] = ar[j - 1];
				ar[j - 1] = temp;
			}
		}
		for (int num = 0; num < ar_size; num++)
		{
			cout << ar[num] << ' ';
		}
		cout << endl << "j loop times: " << count << endl;
		count_i++;
	}
	cout << "i loop times: " << count_i << endl;
}

int nonContiguousSum(int size, int *array) {
	int postiveNum = 0;
	int maxNum = -100000;
	int sum = 0;
	bool *flags;
	flags = new bool[size];
	for (int i = 0; i < size; i++)
	{
		flags[i] = false;
		if (array[i] > 0)
		{
			flags[i] = true;
			postiveNum++;
		}
		if (maxNum < array[i])
		{
			maxNum = array[i];
		}
	}

	if (postiveNum == 0)
	{
		sum = maxNum;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (flags[i])
			{
				sum += array[i];
			}
		}
	}
	return sum;
}

int contiguousSum(int size, int *array) {
	int sum = 0;
	int max = -100000;
	for (int subLength = 1; subLength < size + 1; subLength++) {
		vector<int*> subArrays;
		int currentLengthMaxSum = 0;
		for (int n = 0; n < size - subLength + 1; n++) {
			int* subArray;
			subArray = new int[subLength];
			for (int k = 0; k < subLength; k++)
			{
				subArray[k] = array[n + k];
			}
			subArrays.push_back(subArray);
		}
		for (auto it = subArrays.begin(); it != subArrays.end(); ++it)
		{
			for (size_t i = 0; i < subLength; i++)
			{
				cout << (*it)[i] << " ";
			}
			cout << endl;
		}
		currentLengthMaxSum = vectorMaxSum(subLength, subArrays);
		if (max < currentLengthMaxSum)
		{
			max = currentLengthMaxSum;
		}
	}
	return max;
}

int vectorMaxSum(int ar_length, vector<int*> intVector) {
	int sum = -100000;
	for (auto it = intVector.begin(); it != intVector.end(); it++)
	{
		int tempSum = 0;
		for (int n = 0; n < ar_length; n++)
		{
			tempSum += (*it)[n];
		}
		if (sum < tempSum)
		{
			sum = tempSum;
		}
	}
	return sum;
}


void quickSort(vector<int>& A, int p, int q)
{
	int r;
	if (p < q)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}

int partition(vector<int>& A, int p, int q)
{
	int x = A[p];
	int i = p;
	int j;

	for (j = p + 1; j < q; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			swap(A[i], A[j]);
		}

	}

	swap(A[i], A[p]);
	return i;
}