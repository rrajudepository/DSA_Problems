#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 6000
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
	ldb n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ldb l=1,r=1000000,mid;
		int cnt=0;
		while(cnt<100)
		{
			mid=(l+r)/2;
			if(mid*mid<=n)
				l=mid;
			else
				r=mid;
			cnt++;
		}
		ll tmp=r*10000;
		r=((ldb)tmp)/10000;
		cout<<fixed<<setprecision(4)<<r<<endl;
	}
    return 0;
}