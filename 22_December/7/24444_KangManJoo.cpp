#include <bits/stdc++.h>

using namespace std;
queue<int> que;
vector<int> Vertex[100001];
int isVisit[100001];
vector<int> sortarr;
int check[100001];

void BFS(int cur,int order) {
	isVisit[cur] = order;
	sortarr.clear();
	for (int i = 0; i < Vertex[cur].size(); i++) {
		if(!isVisit[Vertex[cur][i]]&&check[Vertex[cur][i]]==0)
			sortarr.push_back(Vertex[cur][i]);
		check[Vertex[cur][i]] = 1;
	}
	sort(sortarr.begin(),sortarr.end());

	for (auto node:sortarr) {
		que.push(node);
	}
	if (!que.empty()) {
		int nextNode = que.front();
		que.pop();
		BFS(nextNode,order+1);
	}
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, S;
	cin >> N >> M >> S;
	while (M--) {
		int Pnode, Cnode;
		cin >> Pnode >> Cnode;
		Vertex[Pnode].push_back(Cnode);
		Vertex[Cnode].push_back(Pnode);
	}

	BFS(S,1);
	for (int i = 1; i <= N; i++) {
		cout << isVisit[i] << "\n";
	}
}