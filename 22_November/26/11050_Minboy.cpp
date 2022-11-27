#include <iostream>

using namespace std;

int N, K;

int factorial(int a) {
  if (a == 1 || a == 0)
    return 1;
  else
    return a * factorial(a - 1);
}

void solve() {
  cout << factorial(N) / (factorial(K) * factorial(N - K)) << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  solve();

  return 0;
}