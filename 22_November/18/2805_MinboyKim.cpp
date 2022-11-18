#include <iostream>
using namespace std;

long long N, M;
long long height[1010101];
long long Max;

void solve() {
  long long l = 1, ans = 0;
  while (l <= Max) {
    long long mid = (l + Max) / 2;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      if (height[i] - mid > 0) sum += height[i] - mid;
    }
    if (sum >= M) {
      l = mid + 1;
      ans = mid;
    } else
      Max = mid - 1;
  }
  cout << Max << "\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> height[i];
    if (Max < height[i]) Max = height[i];
  }

  solve();

  return 0;
}