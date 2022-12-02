#include <iostream>
#define S 1000000009

using namespace std;

char Arr[3030][3030];
int dp[3030][3030] = {0};
int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> Arr[i];
  dp[n - 1][m - 1] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i == n - 1 && j == m - 1) continue;
      if (Arr[i][j] == 'E') dp[i][j] = dp[i][j + 1] % S;
      if (Arr[i][j] == 'S') dp[i][j] = dp[i + 1][j] % S;
      if (Arr[i][j] == 'B')
        dp[i][j] = (dp[i][j + 1] % S + dp[i + 1][j] % S) % S;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += dp[i][j] % S;
      ans %= S;
    }
  }
  cout << ans << "\n";
}