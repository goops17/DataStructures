#include <iostream>
using namespace std;

struct Node
{
	int data;						// Int-data of node
	Node* left;						// Pointer to right child
	Node* right;					// Pointer to left child
	Node(int dt = 0);				// Sets data to 0 if not specified
};

Node* z = new Node();				// Instead of NULL
Node* root = z;						// Root node points to z node at start

Node* Insert(Node* root, int data);	// Adds node to BST
Node* Delete(Node* root, int data);	// Removes node from BST
void InorderTrav(Node* t);				// <Left><Data><Right>
void PreorderTrav(Node* t);				// <Data><Left><Right>
void PostorderTrav(Node* t);			// <Left><Right><Data>

int main()
{
	root = Insert(root, 1);
	root = Insert(root, 4);
	root = Insert(root, 7);
	root = Insert(root, 3);
	root = Insert(root, 10);
	root = Insert(root, 8);
	root = Insert(root, 13);
	root = Insert(root, 5);
	root = Insert(root, 11);
	root = Insert(root, 12);
	
	PreorderTrav(root);
	
	cout << "\n\nDeleting node 3:" << endl;
	root = Delete(root, 3);
	PreorderTrav(root);
	cout << "\n\nDeleting node 3:" << endl;
	root = Delete(root, 3);

	PreorderTrav(root);

	cout << endl << endl;
	return 0;
}

// Node constructor
Node::Node(int dt)
{
	data = dt;
	left = z;						// Children points to z node
	right = z;
}

Node* Insert(Node* root, int data)
{
	// Tree/sub tree is not empty
	if (root != z)
	{
		if (data > root->data)	// Insertion node has greater value
			root->right = Insert(root->right, data);
		else						// Insertion node has lesser value
			root->left = Insert(root->left, data);
		return root;				// Returns the node (with new connection)
	}
	// Tree/sub tree is empty
	else
		return new Node(data);		// Creates a new node and returns it
}

Node* Delete(Node* root, int data)
{
	if (root == z)
	{
		cout << "Node does not exist." << endl;
		return root;
	}
	if (data > root->data)				// Node to be deleted is greater
		root->right = Delete(root->right, data);
	else if (data < root->data)			// Node to be deleted is lesser
		root->left = Delete(root->left, data);
	else if (data == root->data)		// If node is found
	{
		// Node has no children
		if (root->left == z && root->right == z)
		{
			delete root;			// Delete node from memory
			root = z;				// Let pointer to root point to z
			return root;			// Return link to z
		}
		// Node has one child
		else if (root->left == z || root->right == z)
		{
			Node* child;			// Stores child of node to be deleted
			if (root->left == z)	// Right child only
				child = root->right;
			else					// Left child only
				child = root->left;
			delete root;			// Delete node
			return child;			// Child node returned
		}
		// Node has two children
		else
		{
			Node* small = root->right;	// Find smallest value in RST
			while (small->left != z)	// As long as there are still left children
				small = small->left;
			root->data = small->data;	// Copy data from smallest node to root
			root->right = Delete(root->right, root->data);	// Delete RST smallest
			return root;				// Return the root
		}
	}
	return root;					// Return root (with changed links)
}

void InorderTrav(Node* t)
{
	if (t != z)						// Tree is not empty
	{
		InorderTrav(t->left);		// Go left
		cout << t->data << " ";		// Print data
		InorderTrav(t->right);		// Go right
	}
}

void PreorderTrav(Node* t)
{
	if (t != z)						// Tree is not empty
	{
		cout << t->data << " ";		// Print data
		PreorderTrav(t->left);		// Go left
		PreorderTrav(t->right);		// Go right
	}
}

void PostorderTrav(Node* t)
{
	if (t != z)						// Tree is not empty
	{
		PostorderTrav(t->left);		// Go left
		PostorderTrav(t->right);	// Go right
		cout << t->data << " ";		// Print data
	}
}
