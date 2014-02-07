#include <iostream>
using namespace std;
// Node structure definition
struct node
{
	int value;
	struct node *left;
	struct node *right;
	struct node *parent;
};

// Binary search tree definition
class BST {
public:
	node *root;
	BST(void) { root = NULL;};
	void preorder_print(node *root);
	void postorder_print(node *root);
	void inorder_print(node *root);
	node * search(node *root, int value);
	node * sucessor(node *new_node);
	node * min(node *new_node);
	void del(BST *bstree, int value);
	void insert(BST *bstree, node *new_node);
};

// Class function to preorder print tree data
// Parameters:
// 		node *root - a pointer to the tree's root
void BST::preorder_print(node *root)
{
	if(root != NULL)
	{
		cout << root->value << endl;
		preorder_print(root->left);
		preorder_print(root->right);
	}
}

// Class function to postorder print tree data
// Parameters:
// 		node *root - a pointer to the tree's root
void BST::postorder_print(node *root)
{
	if(root != NULL)
	{
		postorder_print(root->left);
		postorder_print(root->right);
		cout << root->value << endl;
	}
}

// Class function to inorder print tree data
// Parameters:
// 		node *root - a pointer to the tree's root
void BST::inorder_print(node *root)
{
	if(root != NULL)
	{
		inorder_print(root->left);
		cout << root->value << endl;
		inorder_print(root->right);
	}
}

// Class function to search the tree for a node containing
// a specific value
// Parameters:
// 		node *root - a pointer to the tree's root
//		value - the value to search for
// Returns:
//		- a pointer to the node containing the specified value
//		- NULL if the value could not be found
node * BST::search(node *root, int value)
{
	// If the tree is empty, return NULL
	// If the value is the root's value, return root
	if((root == NULL) || (value == root->value))
	{
		return root;
	}

	// recursively search the rest of the tree for the value
	if(value < root->value)
	{
		return search(root->left, value);
	}

	else
	{
		return search(root->right, value);
	}

	return NULL;
}

// Class function to return the node with the smallest value
// Parameters:
//		node *new_node - a pointer to the node to start the
//						 search at, can be root or any other
//						 node for a sub-tree search
// Returns:
//		- a pointer to the node containing the min value
node * BST::min(node *new_node)
{
	// Check the left-most child's value
	while(new_node->left != NULL)
	{
		new_node = new_node->left;
	}

	return new_node;
}

// Class function to return the next largest inorder value
// to the node provided
// Parameters:
//		node *new_node - a pointer to the node whose successor
//						 we wish to find
// Returns:
//		- a pointer to the node containing the successor value
node * BST::sucessor(node *new_node)
{
	// If there is a right sub-tree, the successor will be the
	// min value of that tree
	if(new_node->right != NULL)
	{
		return min(new_node->right);
	}

	// Find the value if there is no right sub-tree
	else
	{
		node *y = new_node->parent;

		while((y != NULL) && (new_node == y->right))
		{
			new_node = y;
			y = y->parent;
		}

		return y;
	}
}

// Class function to insert a node into a tree
// Parameters:
//		BST *bstree - a pointer to a BST tree
//		node *new_node - a pointer to the node to add
void BST::insert(BST *bstree, node *new_node)
{
	// Insert only if the value is not already in the tree
	if(search(bstree->root, new_node->value) == NULL)
	{
		node *y = NULL;
		node *x = bstree->root;
		// Find the correct place for the node to go
		while(x != NULL)
		{
			y = x;
			if(new_node->value < x->value)
			{
				x = x->left;
			}

			else
			{
				x = x->right;
			}
		}

		new_node->parent = y;

		// Insert root
		if(y == NULL)
		{
			bstree->root = new node;
			bstree->root->left = NULL;
			bstree->root->parent = NULL;
			bstree->root->right = NULL;
			bstree->root->value = new_node->value;
		}

		// Insert the node in the left sub-tree
		else if(new_node->value < y->value)
		{
			y->left = new_node;
		}

		// Insert the node in the right sub-tree
		else
		{
			y->right = new_node;
		}
	}

	// Error message, no action was taken
	else
	{
		cout << "Element already in tree.\n";
	}
}

// Class function to delete a node from a tree
// Parameters:
//		BST *bstree - a pointer to a BST tree
//		value - the value of the node to delete
void BST::del(BST *bstree, int value)
{
	node *deleted = search(bstree->root, value);
	// Delete only if the node is already in the tree
	if(deleted != NULL)
	{
		// Node with no children
		if((deleted->left == NULL) && (deleted->right == NULL))
		{
			// Simply delete the node
			if(deleted->parent->value < deleted->value)
			{
				deleted->parent->right = NULL;
			}

			else
			{
				deleted->parent->left = NULL;
			}
		}

		// None with one child
		if((deleted->left == NULL) || (deleted->right == NULL))
		{
			// Move the pointers
			if(deleted->parent->value < deleted->value)
			{
				deleted->right->parent = deleted->parent;
				deleted->parent->right = deleted->right;
			}

			else
			{
				deleted->left->parent = deleted->parent;
				deleted->parent->left = deleted->left;
			}
		}

		// Node with two children
		if((deleted->left != NULL) && (deleted->right != NULL))
		{
			// Find sucessor node
			node *suc_node = sucessor(deleted);

			// If the sucessor has no children, simply delete it from
			// its original position
			if((suc_node->left == NULL) && (suc_node->right == NULL))
			{
				suc_node->parent->left = NULL;
			}

			// If the sucessor has a child, change the pointers
			if(suc_node->right != NULL)
			{
				suc_node->parent->left = suc_node->right;
				suc_node->right->parent = suc_node->parent;
			}

			// Remove the node to be deleted from its place
			if(deleted->parent->value < deleted->value)
			{
				deleted->parent->right = suc_node;
			}

			else
			{
				deleted->parent->left = suc_node;
			}

			// Copy in the sucessor node to the proper place
			suc_node->parent = deleted->parent;
			suc_node->left = deleted->left;
			suc_node->right = deleted->right;
		}
	}

	// Error message, no action was taken
	else
	{
		cout << "Element not in tree.\n";
	}
}

// Function to execute the user driven menu to test the functionality
// of the class functions
void main(void)
{
	// Create an instance of BST class
	BST tree;
	// Create a pointer to that instance
	BST *ptr = &tree;
	node *new_node;
	// Define valiables for cin to use
	int input, val;
	char print;
	// Original printing of menu
	cout << "Please enter the number of the option for the binary search tree." << endl;
	cout << "\t1. Insert element into the tree.\n";
	cout << "\t2. Delete an element from the tree.\n";
	cout << "\t3. Check binary tree by printing.\n";
	cout << "\t4. Quit program.\n";
	cin >> input;

	// Keep polling for user input until the user quits the program
	while(input != 4)
	{
		// User chose insert
		if(input == 1)
		{
			// Prompt for the value to be added to the tree
			cout << "Enter the value to be added: ";
			cin >> val;
			// Create the new node
			new_node = new node;
			new_node->value = val;
			new_node->left = NULL;
			new_node->parent = NULL;
			new_node->right = NULL;
			tree.insert(ptr, new_node);
		}

		// User chose delete
		else if(input == 2)
		{
			// Prompt for the value to be deleted from the tree
			cout << "Enter the value to be deleted: ";
			cin >> val;
			tree.del(ptr, val);
		}

		// User chose print
		else if(input == 3)
		{
			// Sub-menu for printing choices
			cout << "Please enter the letter if the type of print." << endl;
			cout << "\ta. Inorder.\n";
			cout << "\tb. Postprder.\n";
			cout << "\tc. Preorder.\n";
			cin >> print;

			// User chose inorder print
			if(print == 'a')
			{
				tree.inorder_print(tree.root);
			}

			// User chose postorder print
			else if(print == 'b')
			{
				tree.postorder_print(tree.root);
			}

			// User chose preorder print
			else if(print == 'c')
			{
				tree.preorder_print(tree.root);
			}

			// User entered a unknown choice
			else
			{
				cout << "Invalid input!\n";
			}
		}

		// User entered a unknown choice
		else
		{
			cout << "Invalid input!\n";
		}

		cout << "Please enter another number of the option for the binary search tree." << endl;
		cout << "\t1. Insert element into the tree.\n";
		cout << "\t2. Delete an element from the tree.\n";
		cout << "\t3. Check binary tree by printing.\n";
		cout << "\t4. Quit program.\n";
		cin >> input;
	}
}

