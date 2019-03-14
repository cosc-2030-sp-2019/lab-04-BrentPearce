#include<iostream>

using namespace std;

struct Node{
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;
};

Node * searchNode(Node * root, int value){
	Node * rightResult;
	Node * leftResult;
	if(root == NULL){
		return NULL;
	}
	else if (root->value == value){
		return root;
	}
	else{
		rightResult = searchNode(root->rightNode, value);
		leftResult = searchNode(root->leftNode, value);
		if (rightResult == NULL && leftResult == NULL){
			return NULL;
		}
		else if(rightResult != NULL){
			return rightResult;
		}
		else{
			return leftResult;
		}
	}
}

void insertLeft(Node * Parent, Node * nodeToInsert)
{
	Parent->leftNode= nodeToInsert;
	return;
}

void insertRight(Node * Parent, Node * nodeToInsert)
{
	Parent->rightNode= nodeToInsert;
	return;
}


void preOrderTransversal(Node * root){
	if(root != NULL){
		cout << root->value << endl;
		
		preOrderTransversal(root->leftNode);
		
		preOrderTransversal(root->rightNode);

		return;
	}
}

void postOrderTransversal(Node * root)
{
	if (root != NULL)
	{
		postOrderTransversal(root->leftNode);
		postOrderTransversal(root->rightNode);
		cout << root->value << endl;
	}
	return;
}

void inOrderTransversal(Node * root)
{
	if (root != NULL)
	{
		inOrderTransversal(root->leftNode);
		cout << root->value << endl;
		inOrderTransversal(root->rightNode);
	}
	return;
}


int main()
{
	//create root BinaryTree: value = 5
	Node * BinaryTree = new Node;
	BinaryTree->value = 5;
	
	// create a node pointer for searching and setting future nodes.  
	Node * nodePointer = NULL;

	// create new node tmp with value 1 and assign it to right of BinaryTree
	Node * tmp = new Node;
	tmp->value = 1;
	insertRight(BinaryTree, tmp);
	
	// reassign node tmp value 4 and assign it to left of BinaryTree
	tmp = new Node;
	tmp->value = 4;
	insertLeft(BinaryTree, tmp);
	
	// new tmp to create node left of 4.
	tmp = new Node;
	tmp->value = 10;
	nodePointer = searchNode(BinaryTree, 4);
	insertLeft(nodePointer, tmp);

	// new tmp create left of 4.
	tmp = new Node;
	tmp->value = 15;
	insertRight(nodePointer,tmp);

	// filling in the rest of the tree as above
	tmp = new Node;
	tmp->value = 8;
	nodePointer = searchNode(BinaryTree, 15);
	insertLeft(nodePointer, tmp);

	tmp = new Node;
	tmp->value = 7;
	nodePointer = searchNode(BinaryTree, 1);
	insertRight(nodePointer, tmp);

	tmp = new Node;
	tmp->value = 9;
	nodePointer = searchNode(BinaryTree, 7);
	insertRight(nodePointer, tmp);

	cout << "The preorder Traversal of the binary tree" << endl;
	preOrderTransversal(BinaryTree);
	cout << endl << "The postorder Traversals of the binary tree" << endl;
	postOrderTransversal(BinaryTree);
	cout << endl << "The inorder Traversal of the binary tree" << endl;
	inOrderTransversal(BinaryTree);
	Node * searchResult = searchNode(BinaryTree, 2);
	if (searchResult != NULL){
		cout << searchResult << endl;
	}
	else{
		cout << "The node searched does not exist." << endl;
	}

	cout << "Press Enter to end" << endl;
	cin.get();

	return 0;
}
