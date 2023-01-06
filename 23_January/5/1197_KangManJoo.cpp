#include <bits/stdc++.h>

using namespace std;

int v, e;
typedef pair<int, int> pr;
vector<pr> Node[10101];
priority_queue<pr,vector<pr>,greater<pr>> pq;      //parameter = datatype, vector<datatype>, greater <= ascending 
bool checked[10101];
pr to_node;
int sum;

void solve() {
	int cur = 1;
	int plag=1;

	while (plag) {
		plag = 0;
 	checked[cur] = true;
		for (int i = 0; i < Node[cur].size(); i++) {       // 
			if (!checked[Node[cur][i].first]) {
				to_node=make_pair(Node[cur][i].second , Node[cur][i].first);  // cost, nextnode
				pq.push(to_node);
			}
	}
		while (!pq.empty()) {
  	to_node = pq.top();
			pq.pop();
		if (checked[to_node.second]) continue;
  		else {
				sum += to_node.first;
				cur = to_node.second;
				plag = 1;
				break;
			}
		}
	}
	cout << sum;
}

void init() {
	int Pnode, Nnode,cost;
	cin >> v >> e;
	while (e--) {
    cin >> Pnode >> Nnode >> cost;
		Node[Pnode].push_back({ Nnode, cost });          //start node, end node, cost
		Node[Nnode].push_back({ Pnode, cost });

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
