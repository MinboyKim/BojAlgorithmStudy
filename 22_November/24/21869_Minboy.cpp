#include <iostream>

using namespace std;

int N;

void solve() {
  int M = 0;
  if (N == 1) {
    M = 1;
    cout << M << "\n";
    cout << "1 1\n";
    return;
  } else if (N == 2) {
    M = 2;
    cout << M << "\n";
    cout << "1 1\n1 2\n";
    return;
  } else {
    M = N + N - 2;
    cout << M << "\n";
    for (int i = 1; i <= N; i++) {
      cout << 1 << " " << i << "\n";
    }
    for (int i = 2; i < N; i++) {
      cout << N << " " << i << "\n";
    }
  }
}

int main(void) {
  cin >> N;

  solve();

  return 0;
}