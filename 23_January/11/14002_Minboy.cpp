#include <iostream>
#include <vector>

using namespace std;

int N, maxIndex;
int Arr[1010];
int dp[1010];
int trace[1010];
vector<int> ans;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
    trace[i] = -1;
  }

  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (Arr[j] < Arr[i]) {
        if (dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          trace[i] = j;
        }
      }
      if (dp[maxIndex] < dp[i]) maxIndex = i;
    }
  }

  while (maxIndex != -1) {
    ans.push_back(Arr[maxIndex]);
    maxIndex = trace[maxIndex];
  }

  cout << ans.size() << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}