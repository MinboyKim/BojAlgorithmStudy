#include <bits/stdc++.h>

using namespace std;

int N, S, P;
//1~S is support
vector<int> vertex[333333];
vector<int> supportLoad;
bool visited[333333];

void dfs(int cur, int sum) {
	visited[cur] = true;
	if (1 <= cur&& cur<= S) {
		supportLoad.push_back(sum);
	}
	for (int i = 0; i < vertex[cur].size(); i++) {
		if(!visited[vertex[cur][i]])
			dfs(vertex[cur][i], sum + 1);
	}
	return;
}

void init() {
	cin >> N >> S >> P;
	int V1, V2;
	for (int i = 0; i < N - 1; i++) {
		cin >> V1 >> V2;
		vertex[V1].push_back(V2);
		vertex[V2].push_back(V1);
	}
	dfs(P,0);
	return;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	init();
	sort(supportLoad.begin(), supportLoad.end());

	cout<<N-1-supportLoad[0] - supportLoad[1];
	return 0;
}