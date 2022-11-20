#include <iostream>

using namespace std;

long long K, N, Max;
long long wire[10101];

void solve() {
  long long l = 1;
  while (l <= Max) {
    long long mid = (l + Max) / 2;
    long long cnt = 0;
    for (int i = 0; i < K; i++) {
      cnt += wire[i] / mid;
    }
    if (cnt >= N)
      l = mid + 1;
    else
      Max = mid - 1;
  }
  cout << Max << "\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K >> N;

  for (int i = 0; i < K; i++) {
    cin >> wire[i];
    if (wire[i] > Max) Max = wire[i];
  }
  solve();

  return 0;
}