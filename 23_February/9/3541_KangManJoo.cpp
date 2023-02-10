#include <bits/stdc++.h>

using namespace std;

int n,m;
int minF=2000000000;
int eleNum;
pair<int,int> eleve[2020];
int arr[2020];

void solve(){
    int cnt,curFloor,up,down,cur;
    
    for(int i=0; i<eleNum; i++){
        curFloor=0;
        cnt=n;
        up=eleve[i].first;
        down=eleve[i].second;
        cur=1;
        while(cnt--){
            curFloor=(curFloor>=down) ?curFloor-=down:curFloor+=up;
            arr[cur]=curFloor;
            if(cur!=0 && arr[cur]==arr[0]){
                break;
            }
            cur++;
        }
        if(cnt>0){
            cnt=cnt%cur;
            curFloor=arr[cnt];
        }
        if(curFloor==0) curFloor=down+up;
        if(curFloor<minF) minF=curFloor;
    }
    cout<<minF;
}

void init(){
    while(m--){
        cin>>eleve[eleNum].first>>eleve[eleNum].second;
        eleNum++;
    }
    solve();
    return;
}

int main(){
    cin>>n>>m;
    init();

    return 0;
}