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

BSTnode *CreateBST(BSTnode*, int);
void Inorder(BSTnode*);

int main()
{
	//cout << "hello world!" << endl;
	StringManipulate sm("2k34lj233jlkj;kjh5lk4l34j5li3uh5liu3i5uhluhluhuuhi167lk8hl3h76457u67hli82uhli86l24h5iu224");
	cout << sm.FindNumInThree()<<endl;
	
	BSTnode* bstNode = NULL;
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
	tm->PostOrderTraversal(tm->root);

	system("pause");
	return 0;
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
			if (element>root->data)
			root->right = CreateBST(root->right, element);
			else
				printf(" Duplicate Element !! Not Allowed !!!");

				return(root);

	}
}

void Inorder(BSTnode *root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		printf(" %d ", root->data);
		Inorder(root->right);
	}
}
