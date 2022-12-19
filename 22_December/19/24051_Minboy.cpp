#include <iostream>

using namespace std;

int N, K, cnt, ans;
int Arr[10101];

void solve() {
  for (int i = 2; i <= N; i++) {
    int loc = i - 1;
    int newItem = Arr[i];
    while (1 <= loc && newItem < Arr[loc]) {
      Arr[loc + 1] = Arr[loc];
      cnt++;
      if (cnt == K) ans = Arr[loc];
      loc--;
    }
    if (loc + 1 != i) {
      Arr[loc + 1] = newItem;
      cnt++;
      if (cnt == K) ans = newItem;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> Arr[i + 1];
  solve();
  if (cnt < K)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
  return 0;
}