#include <bits/stdc++.h>

using namespace std;

int n, e;
typedef pair<int, int> pr;
vector<pr> Node[1000];
int costs[1000];
int suma,sumb,sum;
priority_queue<pr, vector<pr>, greater<pr>> pq;

 void dijk(int cur,int curCost){
	 costs[cur] = curCost;
	 pr nextNode;
	 for (int i = 0; i < Node[cur].size(); i++) {
		 nextNode = Node[cur][i];
		 nextNode.second += curCost;
		 if (costs[nextNode.first] > nextNode.second) {
			 costs[nextNode.first]=nextNode.second;
			 pq.push(nextNode);
		 }
	 }
	 while (!pq.empty()) {
		 nextNode = pq.top();
		 pq.pop();
		 if (costs[nextNode.first] < nextNode.second)continue;
		 dijk(nextNode.first, nextNode.second);
		 break;
	 }
	return;
 }
 

 void init() {
	int Pnode, Nnode, cost;
	cin >> n >> e;
	while (e--) {
		cin >> Pnode>>Nnode>>cost;
		Node[Pnode].push_back({ Nnode,cost });
		Node[Nnode].push_back({ Pnode,cost });
	}

	return;
}

 void initcost() {
	 for (int i = 1; i <= n; i++) {
		 costs[i] = 99999999;
	 }
 }

 int findMin(int a, int b) {
	 initcost();
	 dijk(1, 0);
	 suma += costs[a];
	 sumb += costs[b];
	 initcost();
	 dijk(a, 0);
	 suma += costs[b];
	 sumb += costs[n];
	 initcost();
	 dijk(b, 0);
	 suma += costs[n];
	 sumb += costs[a];
	 return (suma < sumb) ? suma : sumb;
 }
int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();

	 int a, b;
	 cin >> a >> b;
	 sum=findMin(a, b);

	 if (sum >= 99999999)cout << -1;
	 else cout << sum;

	 return 0;
}