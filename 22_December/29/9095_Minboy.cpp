#include <iostream>

using namespace std;

int dp[15] = {0, 1, 2, 4};
int T;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 4; i < 12; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }

  return 0;
}