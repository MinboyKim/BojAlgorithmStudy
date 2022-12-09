#include <bits/stdc++.h>

using namespace std;
int N, V, M;
vector<int> vertex[1001];
bool visited[1001];

void dfs(int cur) {
	cout << cur << " ";
	visited[cur] = true;
	for (int i = 0; i < vertex[cur].size(); i++) {
		if (!visited[vertex[cur][i]]) {
			dfs(vertex[cur][i]);
		}
	}
	return;
}

void bfs() {
	int cur = V;
	queue<int> que;
	visited[V] = true;
	while (true) {
		cout << cur << " ";
		for (int i = 0; i < vertex[cur].size(); i++) {
			if(!visited[vertex[cur][i]])
				que.push(vertex[cur][i]);
			visited[vertex[cur][i]] = true;
		}
		if (que.empty()) break;
		cur= que.front();
		que.pop();
	}
}
void init_visited() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	cout << "\n";
}

void init() {
	int Pnode, Nnode;
	cin >> N >> M >> V;
	while (M--) {
		cin >> Pnode >> Nnode;
		vertex[Pnode].push_back(Nnode);
		vertex[Nnode].push_back(Pnode);
	}
	for (int i = 1; i <= N; i++) {
		sort(vertex[i].begin(), vertex[i].end());   //smaller one visit first
	}

	dfs(V);
	init_visited();
	bfs();
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}