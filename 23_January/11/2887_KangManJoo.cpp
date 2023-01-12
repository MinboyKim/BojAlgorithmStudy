#include <bits/stdc++.h>

using namespace std;

int n;
typedef tuple <int, int, int> tp;
typedef pair<int, int> pr;
vector<pr> edgeX;
vector<pr> edgeY;
vector<pr> edgeZ;
int parent[100001];
int sum;

struct cmp {
	bool operator()(tp t, tp u) {
		return get<2>(t) > get<2>(u);
	}
};

priority_queue<tp, vector<tp>, cmp> pq;

int findParent(int x) {
	if (parent[x] == x) return x;
	else {
		return findParent(parent[x]);
	}
}

void Union(int x, int y) {
	int newP = findParent(x);
	int tmp;
	while (true) {
		if (parent[y] == y) {
			parent[y] = newP;
			break;
		}
		tmp = parent[y];
		parent[y] = newP;
		y = tmp;
	}
	return;
}

int minLen(int a, int b, int c) {
	int tmp = (a > b) ? b : a;
	return (tmp > c) ? c : tmp;
}

void solve() {
	tp t;
	int Pnode, Nnode;
	while (!pq.empty()) {
		t = pq.top();
		pq.pop();
		Pnode = get<0>(t);
		Nnode = get<1>(t);
		if (findParent(Pnode) == findParent(Nnode)) continue;
		Union(Pnode, Nnode);
		sum += get<2>(t);
	}
	cout << sum;
	return;
}


void init() {
	cin >> n;
	int x, y, z, cost;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		edgeX.push_back({ x,i });
		edgeY.push_back({ y,i });
		edgeZ.push_back({ z,i });
	}
	sort(edgeX.begin(), edgeX.end());
	sort(edgeY.begin(), edgeY.end());
	sort(edgeZ.begin(), edgeZ.end());

	for (int i = 0; i < n - 1; i++) {
		cost = edgeX[i + 1].first - edgeX[i].first;
		pq.push({ edgeX[i].second,edgeX[i + 1].second,cost });

		cost = edgeY[i + 1].first - edgeY[i].first;
		pq.push({ edgeY[i].second,edgeY[i + 1].second,cost });

		cost = edgeZ[i + 1].first - edgeZ[i].first;
		pq.push({ edgeZ[i].second,edgeZ[i + 1].second,cost });
	}
	int i = 0;
	for (auto& cur : parent) {
		cur = i;
		i++;
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