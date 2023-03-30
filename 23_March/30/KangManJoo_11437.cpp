#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> Nodes[100005];
int checked[100005];
int lv[100005];
int lvArr[100005][20];  //ancester node

int LCA(int x, int y){
    while(true){
        if(x==y) return x;
        x=lvArr[x][0];
        y=lvArr[y][0];
    }
}

int findLCA2(int x, int y){
    if(lv[x]==lv[y]) return LCA(x,y);

    int i=0;
    while(true){
        if(lv[lvArr[x][i]]>=lv[y])
            i++;
        else{
            i--;
            break;
        }
    }
    return findLCA2(lvArr[x][i],y);
}

int findLCA(int x,int y){  
    if(lv[x]==lv[y]){
        return LCA(x,y);
    }

    int i=0;
    while(lvArr[x][i]){
        i++;
    }
    i--;

    while(true){
        if(lv[lvArr[x][i]]<lv[y]) {
            i--;
        }
        else {
            break;
        }
    }

    return findLCA2(lvArr[x][i],y);
}


void makeAncester(int cur,int parent){
    int i=0;
    while(parent){
        lvArr[cur][i]=parent;
        parent=lvArr[parent][i];
        i++;
    }
    return;
}

void dfs(int cur,int curLv){
    lv[cur]=curLv;
    checked[cur]=1;
    for(int i=0; i<Nodes[cur].size(); i++){
        if(checked[Nodes[cur][i]]) continue;
        makeAncester(Nodes[cur][i],cur);
        dfs(Nodes[cur][i],curLv+1);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    int pNode,nNode;
    for(int i=0; i<n-1; i++){
        cin>>pNode>>nNode;
        Nodes[pNode].push_back(nNode);
        Nodes[nNode].push_back(pNode);
    }
    dfs(1,1);

    int pr1,pr2;
    cin>>m;
    while(m--){
        cin>>pr1>>pr2;
        if(lv[pr1]>=lv[pr2])
            cout<<findLCA(pr1,pr2)<<'\n';
        else
            cout<<findLCA(pr2,pr1)<<'\n';
    }
    return 0;
}