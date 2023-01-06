#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef tuple<int , int, int> tp;
int UnionFind[1111];
vector<int> UF[1111];
tp Edge;
int sum;

struct cmp {
	bool operator()(tp t, tp u) {
		return get<2>(t) > get<2>(u);     //ascending 
	}
};

priority_queue<tp,vector<tp>,cmp> que;

void changeUnion(int next,int pre) {
	for (int i = 0; i < UF[pre].size(); i++) {
		UnionFind[UF[pre][i]] = next;
		UF[next].push_back(UF[pre][i]);
	}
}

 void solve(){
	 while (true) {
		 Edge = que.top();
		 que.pop();
		 if (UnionFind[get<0>(Edge)] != UnionFind[get<1>(Edge)]) {   // each node is not same group
			 if (UF[UnionFind[get<0>(Edge)]].size() >= UF[UnionFind[get<1>(Edge)]].size()) {
				 changeUnion(UnionFind[get<0>(Edge)], UnionFind[get<1>(Edge)]);			 
			 }
			 else {
				 changeUnion(UnionFind[get<1>(Edge)], UnionFind[get<0>(Edge)]);
			 }
			 sum += get<2>(Edge);
			 if (UF[UnionFind[get<0>(Edge)]].size() >= n|| UF[UnionFind[get<1>(Edge)]].size() >= n) break;
		 }
	 }
	 cout << sum;
	return;
 }
 


void init() {
	int Pnode, Nnode, cost;
	cin >> n >> m;
	int i = n;
	while (i--) {
		UnionFind[i + 1] = i + 1;
		UF[i+1].push_back(i+1);
	}
	while (m--) {
		cin >> Pnode >> Nnode >> cost;
		
		Edge = make_tuple(Pnode,Nnode,cost);
		que.push(Edge);
	}
	solve();
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}