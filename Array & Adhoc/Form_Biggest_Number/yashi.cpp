#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int toCompare(string A, string B)
{

    string AB = A.append(B);

    string BA = B.append(A);
    return AB.compare(BA) > 0 ? 1: 0;
}
void printLargest(vector<string> arr)
{
    sort(arr.begin(), arr.end(), toCompare);

    for (int i=0; i < arr.size() ; i++)
    {

        cout << arr[i];
    }
    cout<<endl;

}


int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
     cin>>n;
     string input;
     vector<string> arr;
     for(int j=0;j<n;j++)
     {
         cin>>input;

    arr.push_back(input);
     }

    printLargest(arr);
    }
}