#include <iostream>

using namespace std;

int N, ans;
int Arr[1010];
int dp1[1010];
int dp2[1010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  for (int i = 0; i < N; i++) {
    dp1[i] = 1;
    for (int j = 0; j < i; j++) {
      if (Arr[j] < Arr[i]) {
        dp1[i] = max(dp1[i], dp1[j] + 1);
      }
    }
  }

  for (int i = N; i >= 0; i--) {
    dp2[i] = 1;
    for (int j = N - 1; j > i; j--) {
      if (Arr[j] < Arr[i]) {
        dp2[i] = max(dp2[i], dp2[j] + 1);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    ans = max(ans, dp1[i] + dp2[i] - 1);
  }

  cout << ans << "\n";

  return 0;
}