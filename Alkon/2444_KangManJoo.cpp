#include <iostream>

using namespace std;

int n;

int main(){
    cin>>n;
    int cnt=0;
    while(true){
        for(int i=0; i<n-cnt-1; i++){
            cout<<" ";
        }
        for(int i=0; i<cnt*2+1; i++){
            cout<<"*";
        }
        cout<<endl;

        cnt++;
        if(cnt==n){
            cnt=n-2;
            break;
        }
    }
    while(true){
        for(int i=0; i<n-cnt-1; i++){
            cout<<" ";
        }
        for(int i=0; i<cnt*2+1; i++){
            cout<<"*";
        }
        cout<<endl;
        cnt--;
        if(cnt<0){
            break;
        }
    }
}