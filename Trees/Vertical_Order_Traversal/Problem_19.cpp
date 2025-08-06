// C++ program to construct a Binary Tree from parent array
//#include"/Users/codingblocks/Documents/All Code/stdc++.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// A tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function to create new Node
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// Creates a node with key as 'i'. If i is root, then it changes
// root. If parent of i is not created, then it creates parent first
void createNode(int parent[], int i, Node *created[], Node **root)
{
	// If this node is already created
	if (created[i] != NULL)
		return;

	// Create a new node and set created[i]
	created[i] = newNode(i);

	// If 'i' is root, change root pointer and return
	if (parent[i] == -1)
	{
		*root = created[i];
		return;
	}

	// If parent is not created, then create parent first
	if (created[parent[i]] == NULL)
		createNode(parent, parent[i], created, root);

	// Find parent pointer
	Node *p = created[parent[i]];

	// If this is first child of parent
	if (p->left == NULL)
		p->left = created[i];
	else // If second child
		p->right = created[i];
}

// Creates tree from parent[0..n-1] and returns root of the created tree
Node *createTree(int parent[], int n)
{
	// Create an array created[] to keep track
	// of created nodes, initialize all entries
	// as NULL
	Node *created[n];
	for (int i=0; i<n; i++)
		created[i] = NULL;

	Node *root = NULL;
	for (int i=0; i<n; i++)
		createNode(parent, i, created, &root);

	return root;
}

//For adding new line in a program
inline void newLine(){
	cout << "\n";
}

// Utility function to do inorder traversal
void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

void findMinMax(Node *node, int *min, int *max, int hd)
{
	// Base case
	if (node == NULL) return;

	// Update min and max
	if (hd < *min) *min = hd;
	else if (hd > *max) *max = hd;

	// Recur for left and right subtrees
	findMinMax(node->left, min, max, hd-1);
	findMinMax(node->right, min, max, hd+1);
}

// A utility function to print all nodes on a given line_no.
// hd is horizontal distance of current node with respect to root.
void printVerticalLine(Node *node, int line_no, int hd)
{
	// Base case
	if (node == NULL) return;

	// If this node is on the given line number
	if (hd == line_no)
		cout << node->key << " ";

	// Recur for left and right subtrees
	printVerticalLine(node->left, line_no, hd-1);
	printVerticalLine(node->right, line_no, hd+1);
}

// The main function that prints a given binary tree in
// vertical order
void verticalOrder(Node *root)
{
	// Find min and max distances with resepect to root
	int min = 0, max = 0;
	findMinMax(root, &min, &max, 0);

	// Iterate through all possible vertical lines starting
	// from the leftmost line and print nodes line by line
	for (int line_no = min; line_no <= max; line_no++)
	{
		printVerticalLine(root, line_no, 0);
		cout << endl;
	}
}




// Driver method
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int parent[n];
		for(int j=0;j<n;j++)
		{
			cin>>parent[j];
		}
		Node *root = createTree(parent, n);
		//inorder(root);
		verticalOrder(root);
		//newLine();
	}
	// //int parent[] = {-1, 0, 0, 1, 1, 3, 5};
	// int parent[] = {4,-1,1,1,2,2,3,3,6,7};
	// int n = sizeof parent / sizeof parent[0];
	// Node *root = createTree(parent, n);
 //     //problem_1 (print inorder)
	// cout << "Inorder Traversal of constructed tree \n";
	// inorder(root);

 //     //Problem_2 (Vertical order traversal)
	// //cout << "Vertical order traversal is \n";
	// //verticalOrder(root);
	// newLine();

	//problem_3 (print zig zag level order)
	

}
