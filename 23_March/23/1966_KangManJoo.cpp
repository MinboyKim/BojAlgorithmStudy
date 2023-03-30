#include <bits/stdc++.h>

using namespace std;

int n;
queue <pair<int,int>> q;
int mx;
void solve(int n, int fd){
    mx=-1;
    int arr[101]={0};
    int cnt=0;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[a]++;
        if(i==fd) q.push({a,1});
        else q.push({a,0});

        if(mx<a) mx=a;
    }
    pair<int,int> pr;
    while(true){
        pr=q.front();
        q.pop();
        if(pr.first==mx){
            arr[mx]--;
            cnt++;
            while(!arr[mx]){
                mx--;
            }
            if(pr.second==1) break;            
        }
        else{
            q.push(pr);
        }
    }
    cout<<cnt;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    while(t--){
        int n,fd;
        cin>>n>>fd;
        solve(n,fd);
    }
    return 0;
}