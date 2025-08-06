#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    long arrx[100000];
    long arry[100000];
    for(int i=0;i<n;i++)
        cin>>arrx[i]>>arry[i];
    sort(arrx,arrx+n);
    sort(arry,arry+n);
    long ansx=0,ansy=0;
    long px=0,py=0;
    for(int i=0;i<n;i++){
        ansx=max(ansx,arrx[i]-px);
        ansy=max(ansy,arry[i]-py);
    }
    cout<<(ansx-1)*(ansy-1);
    return 0;
}
