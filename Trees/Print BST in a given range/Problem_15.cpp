// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
void preorder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preorder(root->left);
		
		preorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node;
}



void Print(struct node *root, int k1, int k2)
{
/* base case */
if ( NULL == root )
	return;

/* Since the desired o/p is sorted, recurse for left subtree first
	If root->data is greater than k1, then only we can get o/p keys
	in left subtree */
if ( k1 < root->key )
	Print(root->left, k1, k2);

/* if root's data lies in range, then prints root's data */
if ( k1 <= root->key && k2 >= root->key )
	printf("%d ", root->key );

/* If root->data is smaller than k2, then only we can get o/p keys
	in right subtree */
if ( k2 > root->key )
	Print(root->right, k1, k2);
}



// Driver Program to test above functions
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
	int n;
	scanf("%d", &n);
	int x;
	scanf("%d", &x);
	struct node *root = NULL;
	
	root = insert(root, x);
	for(int i=1;i<n;i++)
	{
	    scanf("%d", &x);
	    insert(root, x);
	}
	/*insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);*/

     int k1,k2;
     scanf("%d", &k1 );
     scanf("%d", &k2 );
	// print inoder traversal of the BST
	//inorder(root);
     printf("# Preorder : " );
	preorder(root);
	printf("\n");

	// Question : Print BST in a given range
	printf("# Nodes within range are : ");
	Print(root, k1, k2);
	printf("\n");
	root = NULL;
    }
	return 0;
}
