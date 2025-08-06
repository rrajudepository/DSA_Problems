//#include<bits/stdc++.h>
#include"/Users/codingblocks/Documents/All Code/stdc++.h"
using namespace std;

int cnt[2];
int flag;
vector < int > deg[509];
int color[509];

void bfs(int src)
{
    queue <int> myq;
    color[src]=0;
    cnt[0]++;
    myq.push(src);
    while(not myq.empty()){
        int p=myq.front();
        myq.pop();

        for(vector<int>::iterator it=deg[p].begin(); it!=deg[p].end(); it++){
            if(color[*it]==-1){
                color[*it]=1-color[p];
                cnt[1-color[p]]++;
                myq.push(*it);
            }
            else if(color[*it]==color[p])flag=1;
        }
    }
}

void init(int n){
    memset(cnt,0,sizeof(cnt));
    memset(color,-1,sizeof(color));
    flag=0;
    for(int i=0; i<n; i++)
        deg[i].clear();
}
int main(){
    int p;
    cin >> p;
    for(int ii=1; ii<=p; ii++){
        int n;
        cin >> n;
        init(n);
        for(int i=0; i<n; i++){
            int p;
            cin >> p;
            for(int j=0; j<p; j++){
                int x;
                cin >> x;
                deg[i].push_back(x-1);
            }
        }

        for(int i=n-1; i>=0; i--){
            if(color[i]==-1)bfs(i);
        }

        cout << "Case " << ii << ": ";

        if(flag)
        {
         //   cout << "0 0 0\n";
            cout<<"No\n";
        }
        else{
            if(cnt[0]>cnt[1])swap(cnt[0],cnt[1]);
            //cout << 1 << " " << cnt[0] << " " << cnt[1] << endl;
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}