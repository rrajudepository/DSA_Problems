//#include<bits/stdc++.h>
#include"/Users/codingblocks/Documents/All Code/stdc++.h"
using namespace std;

int dp[109][24*70];
pair < int, int > cand[109];

int rec(int i, int curtime){
    //base case
    if(i<0)return 0;
    
    int &ret=dp[i][curtime];

    if(cand[i].first==-1)return ret=rec(i-1,curtime);

    //dp already calculated
    if(ret!=-1)return ret;

    //don't assign for interview: the i'th candidate
    ret=1+rec(i-1,curtime);

    //assign for interview i'th candidate iff possible
    if(curtime+cand[i].second+30<=cand[i].first)
        ret=min(ret, rec(i-1,curtime+cand[i].second));

    return ret;
}

int main(){
    int p;
    cin >> p;
    for(int ii=1; ii<=p; ii++){
        memset(dp,-1,sizeof(dp));
        int n;
        cin >> n;

        for(int i=0; i<n; i++)
            cin >> cand[i].second;

        for(int i=0; i<n; i++)
            cin >> cand[i].first;

        //sort on increasing basis of departure times
        sort(cand,cand+n);

        //reverse, because we'll process the candidate in increasing order of departure times
        reverse(cand,cand+n);

        cout << "Case " << ii << ": " << rec(n-1,0) << endl;
    }
    return 0;
}