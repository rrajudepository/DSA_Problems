#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
 
using namespace std;
 
int M, N;
string s;
#define FOR(i, N) for(int i = 0; i < N; i++)
#define FOR1e(i, N) for(int i = 1; i <= N; i++)
#define REP(i, M, N) for(int i = M; i < N; i++)
#define REPe(i, M, N) for(int i = M; i <= N; i++)
#define sc(N) scanf("%d", &N)
#define scsc(M, N) scanf("%d %d", &M, &N)
#define gt(s) getline(cin, s)
#define all(s) s.begin(), s.end()
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
 
const double PI = 3.14159265;
const int MAX = 123;
const int MOD = 1000000007;
 
int m, n, cnt;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int x[4], y[4];
bool vis[10][10];
 
void bt(int r, int c, int step){
	
	if(r < 0 || r >= m || c < 0 || c >= n) return;
	if(step == m*n && (r != 0 || c != 1)) return;
	FOR1e(i, 3)
		if(step == (i*m*n)/4 && (r != x[i-1] || c != y[i-1])) return;
	if(r == 0 && c == 1 && step == m*n){
		cnt++;
		return;
	}
	FOR(i, 4){
		int x = r+dr[i], y = c+dc[i];
		if(!vis[x][y]){
			vis[x][y] = 1;
			bt(x, y, step+1);
			vis[x][y] = 0;
		}
	}
}
 
int main(){
//	freopen("in.txt", "r", stdin);
	int CASE = 1;
	while(cin >> m >> n){
		if(!m && !n) break;
		FOR(i, 3)
			cin >> x[i] >> y[i];
		cnt = 0;
		memset(vis, 0, sizeof vis);
		bt(0, 0, 1);
		printf("Case %d: %d\n", CASE++, cnt);
	}
	return 0;
}