#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 500100
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 1000000007ll
#define mod1 mod
#define mod2 100000009ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16
 
using namespace std;

int a[nn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		stack<int>s;
		for(int i=0;i<n;i++)
		{
			int ans=0;
			while(!s.empty())
			{
				if(a[s.top()]>a[i])
					break;
				s.pop();
			}
			if(s.empty())
				ans=i+1;
			else
				ans=i-s.top();
			s.push(i);
			cout<<ans<<' ';
		}
		cout<<endl;
	}
    return 0;
}