#include <bits/stdc++.h>

using namespace std;

int t, n, k,findNode;
typedef long long ll;
ll arr[1001];
ll tree[1001];
vector<ll> Node[1001];
int inCount[1001];
queue <int> inCountZero;

 void solve(){
	 while (true) {	 
		 int cur=inCountZero.front();
		 inCountZero.pop();
		 if (cur == findNode) {
			 cout << tree[cur] << endl;
			 break;
		 }
		 for (int j = 0; j < Node[cur].size(); j++) {
			 int nextNode = Node[cur][j];
			 if (tree[nextNode]==arr[nextNode]) tree[nextNode] = arr[nextNode] + tree[cur];
			 else {
				 tree[nextNode] = (tree[nextNode] > arr[nextNode] + tree[cur]) ? tree[nextNode] : arr[nextNode] + tree[cur];
			 }
			 inCount[nextNode]--;
			 if (inCount[nextNode]==0) inCountZero.push(nextNode);
		 }
	 }
	return;
 }
 

void init() {
	int a, b;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			tree[i] = arr[i];
		}
		while (k--) {		
			cin >> a >> b;
			Node[a].push_back(b);
			inCount[b]++;
		}
		for (int cur = 1; cur <= n; cur++) {
			if (inCount[cur] == 0) inCountZero.push(cur);
		}
		cin >> findNode;
		solve();

		for (int i = 1; i <= n; i++) {
			while(!Node[i].empty())
				Node[i].pop_back();
			inCount[i] = 0;
		}
		while (!inCountZero.empty()) inCountZero.pop();
	}
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}