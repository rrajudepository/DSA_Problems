// C++ program to reverse every sub-array formed by
// consecutive k elements
#include <iostream>
using namespace std;

// Function to reverse every sub-array formed by
// consecutive k elements
void reverse(int arr[], int n, int k)
{
	for (int i = 0; i < n; i += k)
	{
		int left = i;

		// to handle case when k is not multiple of n
		int right = min(i + k - 1, n - 1);

		// reverse the sub-array [left, right]
		while (left < right)
			swap(arr[left++], arr[right--]);

	}
}

int fib(int a, int b)
{
	// int i,j;
	// for(int i=0;i<10;i++)
	// {
	// 	a=a+b;
	// 	b=a;
	// }
	int x,y;
	for(int x=0;x<10;x++)
	{
		a=a+b;
		b=a;
	}

  return a;
}

// Driver code
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
        cin>>arr[j];
        int k;
        cin>>k;
        reverse(arr, n, k);
        	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	  cout<<endl;
    }
	/*int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int k = 3;

	int n = sizeof(arr) / sizeof(arr[0]);

	reverse(arr, n, k);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";*/

	return 0;
}
