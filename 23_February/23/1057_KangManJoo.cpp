#include <bits/stdc++.h>

using namespace std;

int n,A,B;

void solve(){
    int GA=A/2+A%2;
    int GB=B/2+B%2;
    int cnt=1;
    while(true){
        if(GA==GB) break;
        GA=GA/2+GA%2;
        GB=GB/2+GB%2;
        cnt++;
    }
    cout<<cnt;
    return;
}

int main(){
    cin>>n>>A>>B;
    solve();

    return 0;
}