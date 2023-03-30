#include <bits/stdc++.h>

using namespace std;

int N,M,B;
int arr[501][501];
tuple<int, int,int> cost[257];


void solve(){
    for(int i=0; i<257; i++){
        for(int row=0; row<N; row++){
            for(int col=0; col<M; col++){
                 if(i<arr[row][col]) {
                    get<0>(cost[i])+=(arr[row][col]-i)*2;
                    get<1>(cost[i])+=(arr[row][col]-i);
                    get<2>(cost[i])=i;
                 }
                 else {
                    get<0>(cost[i])+=(i-arr[row][col]);
                    get<1>(cost[i])-=(i-arr[row][col]);
                    get<2>(cost[i])=i;
                 }
            }
        }
    }

    sort(cost,cost+257);
    for(auto &i: cost){
        if(B+get<1>(i)>=0){
            cout<<get<0>(i)<<" "<<get<2>(i);
            break;
        }
    }

    return;
}

void init(){
    cin>>N>>M>>B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }

    solve();
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();

}