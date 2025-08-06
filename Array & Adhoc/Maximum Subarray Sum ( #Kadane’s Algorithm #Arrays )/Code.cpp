/*input
2
4
1 2 3 4
3
10 -5 10
*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(ll i = a; i <= b; i++)
#define RF(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair<ll,ll>
#define PI 3.14159265358979323846264338327950288
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
ll arr[200005];
ll max_crossing(ll l,ll m,ll r)
{
	ll sum = 0;
	ll left_sum = LLONG_MIN;
	RF(i,m,l)
	{
		sum += arr[i];
		left_sum = max(left_sum,sum);
	}
	ll right_sum = LLONG_MIN;
	sum = 0;
	F(i,m+1,r)
	{
		sum += arr[i];
		right_sum = max(right_sum,sum);
	}
	return (left_sum + right_sum);
}
ll max_subarray(ll l,ll r)
{
	if(l == r)
		return arr[l];
	ll m = (l + r)/2;
	ll a = max_subarray(l,m);
	ll b = max_subarray(m+1,r);
	ll c = max_crossing(l,m,r);
	return max(a,max(b,c));
}
int main() 
{
	std::ios::sync_with_stdio(false);
	freopen("i3.txt","r",stdin);
	freopen("o3.txt","w",stdout);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		F(i,0,n-1)
			cin>>arr[i];
		ll ans = max_subarray(0,n-1);
		cout<<ans<<endl;	
	}
	return 0;
}