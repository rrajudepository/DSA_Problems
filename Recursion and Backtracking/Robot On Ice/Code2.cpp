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
int m, n, cnt;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int x[4], y[4];
bool vis[10][10];

void visit(int r, int c, int step)
{
	//cout<<"h2"<<endl;
	cout<<step<<endl;
	if(r<0 || r>=m || c<0 || c>=n)
	{
		//cout<<"h3"<<endl;
		return;
	}
	if(step==m*n &&(r!=0 || c!=1))
	{
		//cout<<"h4"<<endl;
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(step== (i*m*n)/4 && (r!=x[i-1] || c!=y[i-1]))
		{
			//cout<<"h5"<<endl;
			return;
		}
	}
	if(r==0 && c==1 && step == m*n)
	{
		cout<<"h1"<<endl;
		cnt++;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int x=r+dr[i];
		int y=r+dc[i];
		if(!vis[x][y])
		{
			cout<<"h6"<<endl;
			vis[x][y]=true;
			visit(x,y,step+1);
			vis[x][y]=false;
		}
	}

}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>m>>n;
		for(int j=0;j<3;j++)
		{
          cin>>x[i]>>y[i];
		}
		cnt =0;
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				vis[j][k]=false;
			}
		}
		visit(0,0,1);
		cout<<"Case "<<i+1<<" : "<<cnt<<endl;

	}
}