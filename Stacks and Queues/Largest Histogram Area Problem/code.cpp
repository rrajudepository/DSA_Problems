#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 100100
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
#define cmp 1e-11
 
using namespace std;
const ldb pi=3.141592653589793238462643383;

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
    int n;
    cin>>n;
    stack<int>s;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	while(!s.empty())
    	{
    		if(a[s.top()]<=a[i])
    			break;
    		int j=s.top();
    		s.pop();
    		if(!s.empty())
    			ans=max(ans,a[j]*1ll*(i-s.top()-1));
    		else
    			ans=max(ans,a[j]*1ll*i);
    	}
    	s.push(i);
    }
    while(!s.empty())
    {
    	int j=s.top();
    	s.pop();
    	if(!s.empty())
    		ans=max(ans,a[j]*1ll*(n-s.top()-1));
    	else
    		ans=max(ans,a[j]*1ll*n);
    }
    cout<<ans<<endl;
    return 0;
}