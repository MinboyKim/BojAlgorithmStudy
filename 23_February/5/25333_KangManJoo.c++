#include <bits/stdc++.h>

using namespace std;

int a,b,x;

int findGcd(int A, int B){
    int rtn;
    if(A%B==0){
        return B;
    }
    else{
        return findGcd(B,A%B);
    }
}

void solve(){
    cout<<x/findGcd(a,b)<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>x;
        solve();
    }
    return 0;
}