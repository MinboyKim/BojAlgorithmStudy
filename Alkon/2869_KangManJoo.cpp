#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int newN=n;
    int cnt=0;
    while(true){
        cnt++;
        if(newN<10){
            newN=10*newN+newN;
        }
        else{
            newN=(newN%10)*10+(newN/10+newN%10)%10;
        }
        if(newN==n) break;
    }
    cout<<cnt;
}