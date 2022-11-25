#include <iostream>

using namespace std;

int N;
int honey[101010];
int sum[101010];
int ans;

void solve() {  // 1. 벌 벌 꿀통 2. 벌 꿀통 벌 3. 꿀통 벌 벌
  int temp = 0;
  for (int i = 2; i < N; i++) {  // 1
    temp = (sum[N] - sum[1] - honey[i]) + (sum[N] - sum[i]);
    ans = max(ans, temp);
  }

  for (int i = 2; i < N; i++) {  // 2
    temp = (sum[i] - sum[1]) + (sum[N] - sum[i - 1] - honey[N]);
    ans = max(ans, temp);
  }

  for (int i = 2; i < N; i++) {  // 3
    temp = (sum[i] - honey[i]) + (sum[N] - honey[N] - honey[i]);
    ans = max(ans, temp);
  }

  cout << ans << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> honey[i];
    sum[i] = sum[i - 1] + honey[i];
  }
  solve();

  return 0;
}