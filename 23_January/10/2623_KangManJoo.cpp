#include <bits/stdc++.h>

using namespace std;

int n, m,cnt;
int in_degree[1001];
int visited[1001];
int beingVisited[1001];
int PD[1001];
vector<int> adj[1001];
queue<int> order;
stack<int> stk;
int cycle;

 void dfs(int cur){
		visited[cur] = 1;
		beingVisited[cur] = 1;
		for (int i = 0; i < adj[cur].size(); i++) {
			if (beingVisited[adj[cur][i]]) {
				cout << 0;
				exit(0);
			}
			if (!visited[adj[cur][i]]) {
				dfs(adj[cur][i]);
			}
		} 
		beingVisited[cur] = 0;
		order.push(cur);
		return;
 }
 
void init() {
	int singerNum,singer;
	cin >> n >> m;

	while (m--) {
		cin >> singerNum;
		for (int i = 0; i < singerNum; i++) {
			cin >> PD[i];
		}
		for (int i = 0; i < singerNum; i++) {
			for (int j = 0; j < i; j++) {
				adj[PD[i]].push_back(PD[j]);
			}
		}
	}

	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 for (int i = 1; i <= n; i++) {
		 if (!visited[i]) dfs(i);
	 }
	 
	 while (!order.empty()) {
		 cout << order.front()<<'\n';
		 order.pop();
	 }
	 return 0;
}