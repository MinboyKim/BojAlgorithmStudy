#include <bits/stdc++.h>

using namespace std;

int n,m;
int crain[51];
int box[10001];
int canMove[51];
int moveBox;
int cnt;
void solve(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(crain[j]>=box[i]){
                canMove[j]++;
            }
        }
    }
    while(m>0){
        moveBox=0;
        for(int i=0; i<52; i++){
            if(!canMove[i]) break;
            canMove[i]--;
            moveBox++;
        }
        m-=moveBox;
        cnt++;
    }
    cout<<cnt;
    return;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>crain[i];
    }
    
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>box[i];
    }
    sort(crain,crain+n,greater<>());
    sort(box,box+m,greater<>());

    solve();

    return 0;
}