#include <bits/stdc++.h>

using namespace std;
#define MAX 2147483647
int n;
int m[555];
int dp[501][501];
 void solve(){
	 for (int j = 2; j <= n; j++) {
		 for (int i = 1; i <= n+1 - j; i++) {
			 dp[i][i + j] = MAX;
			 for (int k = 1; k<=j-1; k++) {
				 dp[i][i + j] = min(dp[i][i+j], dp[i][i+k] + dp[i + k][i+j] + m[i] * m[i+k] * m[i+j]);
			 }
		 }
	}
	 cout << dp[1][n+1];
	return;
 }
 

void init() {
	int garbage;
	cin >> n;
	cin >> m[1];
	for (int i = 2; i <= n; i++) {
		cin >> m[i];
		cin >> garbage;
	}
	cin >> m[n+1];
	solve();
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}