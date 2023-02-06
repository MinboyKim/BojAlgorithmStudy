#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<int, int> pr;
vector<pr> Node[1001];
int visited[1001];
long long sum;

struct cmp {
	bool operator()(pr a, pr b) {
		return a.second > b.second;
	}
};

priority_queue<pr, vector<pr>, cmp> edge;

void solve(int cur,int cost) {
	visited[cur] = 1;
	sum += cost;
	for (int i = 0; i < Node[cur].size(); i++) {
		int nextNode = Node[cur][i].first;
		if (visited[nextNode]) continue;
		edge.push(Node[cur][i]);
	}
	pr next;
	while (!edge.empty()) {
		next = edge.top();
		edge.pop();
		if (visited[next.first]) continue;
		solve(next.first,next.second);
		break;
	}
	return;
 }
 

void init() {
	int cost;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost;
			if (i != j) {
				Node[i].push_back({ j,cost });
			}
		}
	}
	solve(1,0);
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 cout << sum;
	 return 0;
}