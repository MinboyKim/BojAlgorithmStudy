#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef pair<int, int> pr;
vector<pr> Node[101'010];
pr edge;
bool checked[101010];
long long sum;
int maxCost;

struct cmp {
	bool operator()(pr t, pr u) {
		return t.second > u.second;
	}
};

priority_queue<pr, vector<pr>, cmp> pq;


 void solve(){
	 int cur = 1;
	 n--;
	 while (n) {
		 checked[cur] = true;
		 for (int i = 0; i < Node[cur].size(); i++) {
			 if (!checked[Node[cur][i].first]) {
				 pq.push(Node[cur][i]);
			 }
		 }
		 while (!pq.empty()) {
			 edge=pq.top();
			 pq.pop();
			 if (checked[edge.first]) continue;			 
			 cur = edge.first;
			 sum += edge.second;
			 if (maxCost < edge.second) maxCost = edge.second;
			 n--;
			 break;
		 }
	 }
	 cout << sum-maxCost;
	return;
 }
 
void init() {
	cin >> n >> m;
	int Pnode, Nnode, cost;
	while (m--) {
		cin >> Pnode >> Nnode >> cost;
		Node[Pnode].push_back({ Nnode,cost });
		Node[Nnode].push_back({ Pnode,cost });
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