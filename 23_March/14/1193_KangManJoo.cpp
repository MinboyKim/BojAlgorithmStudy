#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numerator;
    int denominator;

    int n,cur;
    cin>>n;

    int now=0;
    
    for(cur=1; cur<1000000; cur++){
        now+=cur;
        if(now >=n){
            break;
        }
    }

    int cnt=now-cur+1;

    if(cur%2==0){
        numerator=1;
        denominator=cur;
        for(int j=cnt; j<now; j++){
            if(j==n) break;
            numerator++;
            denominator--;
        }
    }
    else{
        numerator=cur;
        denominator=1;
        for(int j=cnt; j<now; j++){
            if(j==n) break;
            numerator--;
            denominator++;       
        }
    }

   cout<<numerator<<"/"<<denominator;


    return 0;
}