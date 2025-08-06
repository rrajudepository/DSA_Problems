#include"/Users/codingblocks/Documents/All Code/stdc++.h"
//#include <iostream>
//#include<bits/stdc++.h>
using namespace std;
 
vector<int>primes;
vector<long long int> numbers;
int NotPrime[1000005]={1,1,0};//notprime[0]=1,notprime[1]=1, rest by default 0.
 
struct arrays{//Not necessary to use struct, but it makes things convenient for me :)
    int position;
    int index;
    long long int value;
};
 
bool comp2(arrays a,arrays b)
{
    return a.value>b.value;
}
 
void sieve()
{
    int i,j;
    for(i=2;i<=1000000;i++)
    {
        if(NotPrime[i]==1)continue;
        primes.push_back(i);
        for(j=2*i;j<=1000000;j+=i)//j=2*i to prevent overflow :)
        {
            NotPrime[j]=1;
        }
    }
}
void num()
{
    long long int k;
    int i,j;
    for(i=0;i<primes.size();i++)
    {
        j=2;
        k=primes[i];
        while(pow(k,j)<=pow(10,12))
        {
            if(NotPrime[j+1]==0)
            {
                numbers.push_back(pow(k,j));//This vector will store the numbers which represent supporters.
                
            }
            //cout<<"j is "<<j<<endl;
            j+=2;//We can easily do j+=2, since j+1 is odd, and so (j+1)+1=Even= Cant be prime.
        }
    }
}
int main() {
	// your code goes here
	#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
	ios_base::sync_with_stdio(0);//Fast I/O
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	sieve();//Calling Sieve
	num();//To calculate the numbers which are supporters.
	sort(numbers.begin(),numbers.end());
	int index;
	//for(index=0;index<numbers.size();index++)cout<<numbers[index]<<endl;
	//cout<<numbers.size()<<endl;
	while(t--)
	{
	    int n;
	    cin>>n;
	    arrays arr[n];
	    int i;
	    for(i=0;i<n;i++){cin>>arr[i].value;arr[i].index=i;}
	    
	    sort(arr,arr+n,comp2);
	    for(i=0;i<n;i++)arr[i].position=i+1;
	    
	    int flag=0;
	    for(i=0;i<n;i++)
	    {
	        int lb= lower_bound(numbers.begin(),numbers.end(),arr[i].value)-numbers.begin();
	        //Lower bound is preferred, as we dont have to write the code for binary search!
	        //Knowledge of your languages STL and functions is a must, it comes in handy for short contests.
	        
	        if(lb<numbers.size() && numbers[lb]==arr[i].value)
	        {
	            flag++;
	            cout<<arr[i].position<<" ";
	        }
	    }
	    
	    if(flag==0)cout<<"No supporter found.";
	    cout<<"\n";
	}
	
	return 0;
}
 