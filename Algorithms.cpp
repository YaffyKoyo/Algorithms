// algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringManipulate.h"
#include "TreeManipulate.h"
using namespace std;

struct BSTnode
{
	int data;
	BSTnode *left, *right;
};

void NullTerminalStringReverse(char * str);

void replaceSpaces(char str[], int length);

BSTnode *CreateBST(BSTnode*, int);
void Inorder(BSTnode*);

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
	for (size_t i = length-1; i >0; i--)
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
