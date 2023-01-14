#include <iostream>

using namespace std;

int N, ans;
int Arr[1010];
int dp[1010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (Arr[j] < Arr[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";

  return 0;
}