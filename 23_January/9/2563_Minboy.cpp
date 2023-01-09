#include <iostream>

using namespace std;

int N, ans;
int Arr[100][100];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> N;
  while (N--) {
    cin >> a >> b;
    for (int i = a - 1; i < a + 9; i++) {
      for (int j = b - 1; j < b + 9; j++) {
        Arr[i][j]++;
      }
    }
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (Arr[i][j]) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}