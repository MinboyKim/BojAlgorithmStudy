#include <bits/stdc++.h>

using namespace std;

int n;
int arr[20002];
vector<long long> gcds;
int checked[20002];

int findGcd(int x){
    if(arr[x]==x) return 1;
    int nextLoc=arr[x];
    checked[nextLoc]=1;
    int cnt=1;

    while(arr[nextLoc]!=x){
        nextLoc=arr[nextLoc];
        checked[nextLoc]=1;
        cnt++;
    }
    return cnt+1;
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main(){
    int x;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x;
        arr[x]=i;     
    }
    for(int i=1; i<=n; i++){
        if(checked[i]!=1){
            checked[i]=1;
            gcds.push_back(findGcd(i));
        }
    }
    long long tmp;
    if(gcds.size()>=2){
        tmp=lcm(gcds[0],gcds[1]);
    }
    else{
        tmp=gcds[0];
    }
    for(int i=2; i<gcds.size(); i++){
        tmp=lcm(tmp,gcds[i]);
    }
    cout<<tmp;
    
}