//#include <bits/stdc++.h>
#include"/Users/codingblocks/Documents/All Code/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int mat[100][100];
bool visited[100][100];
set<int> out[4];
set<int> in[4];
int n,m;


int bfs(int x,int y,int l)
{
	int ans=0;
	queue< pair<int, pair<int,int> > > q;
	q.push(mp(x,mp(y,1)));
	ans=1;
	visited[x][y]=true;
	while((!q.empty())&&(q.front().se.se<l)){
		pair< int, pair< int,int > > p = q.front();
		q.pop();
		int i = p.fi;
		int j = p.se.fi;
		int k= p.se.se;
		// cout<< i << " " << j << " " << k << "\n";
		if(i-1>=0 && !visited[i-1][j] && out[0].find(mat[i][j])!=out[0].end() && in[0].find(mat[i-1][j])!=in[0].end()){
			visited[i-1][j]=true;
			q.push(mp(i-1,mp(j,k+1)));
			ans++;
			// cout << "a\n";
		}
		if(j+1<m && !visited[i][j+1] && out[1].find(mat[i][j])!=out[1].end() && in[1].find(mat[i][j+1])!=in[1].end()){
			visited[i][j+1]=true;
			q.push(mp(i,mp(j+1,k+1)));
			ans++;
			// cout << "b\n";
		}
		if(i+1<n && !visited[i+1][j] && out[2].find(mat[i][j])!=out[2].end() && in[2].find(mat[i+1][j])!=in[2].end()){
			visited[i+1][j]=true;
			q.push(mp(i+1,mp(j,k+1)));
			ans++;
			// cout << "c\n";
		}
		if(j-1>=0 && !visited[i][j-1] && out[3].find(mat[i][j])!=out[3].end() && in[3].find(mat[i][j-1])!=in[3].end()){
			visited[i][j-1]=true;
			q.push(mp(i,mp(j-1,k+1)));
			ans++;
			// cout << "d\n";
		}
	}
	return ans;
}

int main()
{
	out[0].insert(1);out[0].insert(2);out[0].insert(4);out[0].insert(7);
	out[1].insert(1);out[1].insert(3);out[1].insert(4);out[1].insert(5);
	out[2].insert(1);out[2].insert(2);out[2].insert(5);out[2].insert(6);
	out[3].insert(1);out[3].insert(3);out[3].insert(6);out[3].insert(7);
	in[0].insert(1);in[0].insert(2);in[0].insert(5);in[0].insert(6);
	in[1].insert(1);in[1].insert(3);in[1].insert(6);in[1].insert(7);
	in[2].insert(1);in[2].insert(2);in[2].insert(4);in[2].insert(7);
	in[3].insert(1);in[3].insert(3);in[3].insert(4);in[3].insert(5);
	int t;
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>m;
		int x,y,l;
		cin>>x>>y>>l;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mat[i][j];
				visited[i][j]=false;
			}
		}
		cout<<"#"<<p<<" "<<bfs(x,y,l)<<" \n";
	}
		//cout<<"Hello This is Rajkishor"<<" :"<<t<<"\n";
	return 0;
}

/*
g++ samsung.cpp 
./a.out
*/



