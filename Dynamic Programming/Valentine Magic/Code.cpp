/*input
5 7 
8 11 12 15 21 
7 10 12 15 18 19 20
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
#define INF 10000000000099ll
#define mod 1000000007
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
ll n,m,a[5005],b[5005],dp[5005][5005];
ll f(ll i,ll j)
{
	if(i == n) // if all the boys have been paired
		return 0;
	if(j == m) // if all girls are paired and boys are still left
		return INF;
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll aa = f(i,j+1); // dont pair ith boy with jth girl
	ll bb = f(i+1,j+1) + abs(a[i]-b[j]); // pair ith boy with jth girl
	return dp[i][j] = min(aa,bb);
}
int main() 
{
	std::ios::sync_with_stdio(false);
	//freopen("i4.txt","r",stdin);
	//freopen("o4.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	F(i,0,n-1)
		cin>>a[i];
	F(i,0,m-1)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	ll ans = f(0,0);
	cout<<ans<<endl;
	return 0;
}