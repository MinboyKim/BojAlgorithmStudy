#include <iostream>

using namespace std;

int N, M;
int number[111];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int total = 0, ans = 0;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> number[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        total = number[i] + number[j] + number[k];
        if (ans < total && total < M + 1) ans = total;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}