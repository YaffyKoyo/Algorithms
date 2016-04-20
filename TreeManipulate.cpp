#include "stdafx.h"
#include "TreeManipulate.h"


TreeManipulate::TreeManipulate()
{
}


void TreeManipulate::InsertNode(tree * root, int data)
{
		if (data > root->element) {
			if (!root->_rightNode) {
				root->_rightNode = new tree(data);
			}
			else
			{
				InsertNode(root->_rightNode, data);
			}
		}
		else
		{
			if (!root->_leftNode) {
				root->_leftNode = new tree(data);
				
			}
			else
			{
				InsertNode(root->_leftNode, data);
			}
		}
	
}

void TreeManipulate::Add(int data)
{
	if (root) {
		this->InsertNode(root, data);
	}
	else
	{
		this->root = new tree(data);
		
	}
}

void TreeManipulate::PreOrderTraversal(tree* root)
{
	if (root != NULL) {
		PreOrderTraversal(root->_leftNode);
		std::cout << root->element << " ";
		PreOrderTraversal(root->_rightNode);
	}
}

void TreeManipulate::InOrderTraversal(tree* root)
{
	if (root != NULL) {
		std::cout << root->element << " ";
		InOrderTraversal(root->_leftNode);
		InOrderTraversal(root->_rightNode);
	}
}

void TreeManipulate::PostOrderTraversal(tree* root)
{
	if (root != NULL) {
		PostOrderTraversal(root->_leftNode);
		PostOrderTraversal(root->_rightNode);
		std::cout << root->element << " ";
	}
}

TreeManipulate::~TreeManipulate()
{
}
