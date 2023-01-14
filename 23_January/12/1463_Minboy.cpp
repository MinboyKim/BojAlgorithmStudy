#include <iostream>

using namespace std;

int N;
int dp[1'000'000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 2; i <= N; i++) {
    if (i % 3 == 0) {
      if (i % 2 == 0) {
        dp[i] = min(dp[i / 3] + 1, dp[i / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
        continue;
      }
      dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
      continue;
    } else if (i % 2 == 0) {
      dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
      continue;
    }
    dp[i] = dp[i - 1] + 1;
  }

  cout << dp[N] << "\n";

  return 0;
}