#pragma once



class TreeManipulate
{
	struct tree
	{
		int element;
		tree* _leftNode;
		tree* _rightNode;

		tree(int data) {
			this->element = data;
			this->_leftNode = NULL;
			this->_rightNode = NULL;
		}

	};



public:
	TreeManipulate();
	void InsertNode(tree* root, int data);
	void Add(int data);
	void PreOrderTraversal(tree* root);
	void InOrderTraversal(tree* root);
	void PostOrderTraversal(tree* root);
	~TreeManipulate();

	tree *root;
};



