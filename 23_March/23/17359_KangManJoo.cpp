#include <bits/stdc++.h>

using namespace std;

int n;
string arr[11];
int cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    int i=0;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.length()-1; j++){
            if(s[j]!=s[j+1]){
                cnt++;
            }
        }
        arr[i]=s;
    }   

    cout<<cnt;


}