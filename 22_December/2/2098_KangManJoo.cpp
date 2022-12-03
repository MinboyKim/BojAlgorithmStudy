#include <bits/stdc++.h>

using namespace std;

int path[16][16];
int n;
int dp[16][1 << 16];
int visit;


int find_path(int cur, int visited, int bit) {
	if (bit == n - 1) {
		return dp[cur][visited] = path[cur][0];          //no return path, 0 return	
	}

	if (dp[cur][visited]) return dp[cur][visited];   //have cost, return

	dp[cur][visited] = 1000000000;

	for (int i = 0; i < n; i++) {
		if (path[cur][i] == 0)continue;					 //no path, search x
		if (visited & (1 << i)) continue;			     //visited, revisit x

		int nxtpath = find_path(i, visited | (1 << cur), bit + 1);
		if (!nxtpath) continue;				 //not path to start=> not going
		dp[cur][visited] = min(dp[cur][visited], nxtpath + path[cur][i]);  //not first find => compare


	}

	return dp[cur][visited];

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> path[i][j];
		}
	}

	cout << find_path(0, 0, 0);



	return 0;
}