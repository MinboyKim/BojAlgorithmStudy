#include <bits/stdc++.h>

using namespace std;
vector<int> edge[100000];
vector<int> fanLoc;

void dfs(int x) {
	for (int fan = 0; fan < fanLoc.size(); fan++) {
		if (x== fanLoc[fan]) {
			return;
		}
	}
	for (int i = 0; i < edge[x].size(); i++) {
		dfs(edge[x][i]);
	}
	if (edge[x].size() == 0) {
		cout << "yes";
		exit(0);
	}
	return;
}

int main() {
	int N, M;
	cin >> N >> M;
	int pNode, cNode;
	for (int i = 0; i < M; i++) {
		cin >> pNode >> cNode;
		edge[pNode].push_back(cNode);
	}
	int fan,loc;
	cin >> fan;
	while (fan--) {
		cin >> loc;
		fanLoc.push_back(loc);
	}

	dfs(1);
	cout << "Yes";
	return 0;
}