#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Compare{
public:
    bool operator()(pair<int,long> p1,pair<int,long> p2){
        return p1.second>p2.second;
    }
};
int main(){
    long arr[400000];
    long out[400000];
    priority_queue<pair<int,long> ,vector<pair<int,long> > ,Compare > pq;
    int s,n;
    cin>>s>>n;
    for(int i=0;i<s*n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<s;i++){
        pq.push(pair<int,long>(i*n,arr[i*n]));
    }
    int c=0;
    while(!pq.empty()){

        pair<int,long> p = pq.top();
        pq.pop();
        out[c]=p.second;
        int t = p.first;
        if((t+1)%n!=0)
            pq.push(pair<int,long>(t+1,arr[t+1]));
        c++;
    }
    for(int i=0;i<s*n;i++)
        cout<<out[i]<<" ";
    return 0;
}
