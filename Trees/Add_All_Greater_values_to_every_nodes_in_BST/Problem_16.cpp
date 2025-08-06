// C program to add all greater values in every node of BST
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to add all greater values in every node
void modifyBSTUtil(struct Node *root, int *sum)
{
	// Base Case
	if (root == NULL) return;

	// Recur for right subtree
	modifyBSTUtil(root->right, sum);

	// Now *sum has sum of nodes in right subtree, add
	// root->data to sum and update root->data
	*sum = *sum + root->data;
	root->data = *sum;

	// Recur for left subtree
	modifyBSTUtil(root->left, sum);
}

// A wrapper over modifyBSTUtil()
void modifyBST(struct Node *root)
{
	int sum = 0;
	modifyBSTUtil(root, &sum);
}


void preorder(struct Node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		
		preorder(root->right);
	}
}

// A utility function to do inorder traversal of BST
void inorder(struct Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given data in BST */
struct Node* insert(struct Node* node, int data)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(data);

	/* Otherwise, recur down the tree */
	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	/* return the (unchanged) node pointer */
	return node;
}

// Driver Program to test above functions
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
    	struct Node *root = NULL;
    	int n;
    	scanf("%d", &n);
    	int x ;
    	scanf("%d", &x);
	root = insert(root, x);
	for(int j=1;j<n;j++)
	{
	     scanf("%d", &x);	
		insert(root, x);
	}
    preorder(root);
    printf("\n");
	modifyBST(root);

	// print inoder tarversal of the modified BST
	preorder(root);
	printf("\n");
    }
	// struct Node *root = NULL;
	// root = insert(root, 50);
	// insert(root, 30);
	// insert(root, 20);
	// insert(root, 40);
	// insert(root, 70);
	// insert(root, 60);
	// insert(root, 80);
 //    preorder(root);
	// modifyBST(root);

	// // print inoder tarversal of the modified BST
	// inorder(root);

	return 0;
}
