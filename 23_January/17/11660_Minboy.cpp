#include <iostream>

using namespace std;

int N, M;
int sum[1030][1030];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a;
      sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a;
    }
  }

  while (M--) {
    int x1, x2, y1, y2;
    cin >> y1 >> x1 >> y2 >> x2;

    cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] +
                sum[y1 - 1][x1 - 1]
         << "\n";
  }

  return 0;
}