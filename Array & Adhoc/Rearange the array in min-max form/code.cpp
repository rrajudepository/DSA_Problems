// C++ program to rearrange an array in minimum
// maximum form
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Prints max at first position, min at second position
// second max at third position, second min at fourth
// position and so on.
void rearrange(int arr[], int n)
{
    // Auxiliary array to hold modified array
    int temp[n];
 
    // Indexes of smallest and largest elements
    // from remaining array.
    int small=0, large=n-1;
 
    // To indicate whether we need to copy rmaining
    // largest or remaining smallest at next position
    int flag = true;
 
    // Store result in temp[]
    for (int i=0; i<n; i++)
    {
        if (flag)
            temp[i] = arr[large--];
        else
            temp[i] = arr[small++];
 
        flag = !flag;
    }
 
    // Copy temp[] to arr[]
    for (int i=0; i<n; i++)
        arr[i] = temp[i];
}
 
// Driver program to test above function
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        rearrange(a, n);
        cout<<"# "<<i+1<<": ";
        for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout<<endl;
    }

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int n = sizeof(arr)/sizeof(arr[0]);
 
    // cout << "Original Arrayn";
    // for (int i=0; i<n; i++)
    //     cout << arr[i] << " ";
 
    // rearrange(arr, n);
 
    // cout << "nModified Arrayn";
    // for (int i=0; i<n; i++)
    //     cout << arr[i] << " ";
    return 0;
}