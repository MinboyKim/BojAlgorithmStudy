#include <iostream>

using namespace std;

int P, N, M;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> P;
  while (P--) {
    cin >> N >> M;
    int a = 1, b = 1, cnt = 0;
    while (true) {
      int temp = (a + b) % M;
      a = b;
      b = temp;
      cnt++;
      if (a == 1 && b == 1) break;
    }
    cout << N << " " << cnt << "\n";
  }

  return 0;
}