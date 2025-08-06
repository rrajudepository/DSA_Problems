// C++ program to rotate a matrix by 90 degrees
#include <bits/stdc++.h>
#define N 1000
using namespace std;



// An Inplace function to rotate a N x N matrix
// by 90 degrees in anti-clockwise direction
void rotateMatrix(int mat[N][N], int n)
{
	// Consider all squares one by one
	for (int x = 0; x < n / 2; x++)
	{
		// Consider elements in group of 4 in 
		// current square
		for (int y = x; y < n-x-1; y++)
		{
			// store current cell in temp variable
			int temp = mat[x][y];

			// move values from right to top
			mat[x][y] = mat[y][n-1-x];

			// move values from bottom to right
			mat[y][n-1-x] = mat[n-1-x][n-1-y];

			// move values from left to bottom
			mat[n-1-x][n-1-y] = mat[n-1-y][x];

			// assign temp to left
			mat[n-1-y][x] = temp;
		}
	}
}

// Function to print the matrix
void displayMatrix(int mat[N][N],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%2d ", mat[i][j]);

		printf("\n");
	}
	printf("\n");
}


/* Driver program to test above functions */
int main()
{
	// Test Case 1
	/*int mat[N][N] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};*/


	// Tese Case 2
	/* int mat[N][N] = {
						{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}
					};
	*/

	// Tese Case 3
	/*int mat[N][N] = {
					{1, 2},
					{4, 5}
				};*/

	//displayMatrix(mat);
	int n;
	cin>>n;
	int mat[N][N];
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>mat[i][j];
	    }
	}

	rotateMatrix(mat,n);

	// Print rotated matrix
	displayMatrix(mat, n);

	return 0;
}
