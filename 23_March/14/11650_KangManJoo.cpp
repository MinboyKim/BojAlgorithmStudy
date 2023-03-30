#include <bits/stdc++.h>

using namespace std;
int n;
typedef pair<int,int> pr;
vector<pr> arr;
pr pr1;

bool compare(pr a, pr b){
    if(a.first==b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    cin>>n;
    while(n--){
        cin>>pr1.first>>pr1.second;
        arr.push_back(pr1);
    }
    sort(arr.begin(),arr.end(),compare);

    for(auto i: arr){
        cout<< i.first<<" "<<i.second<<'\n';
    }
 
}