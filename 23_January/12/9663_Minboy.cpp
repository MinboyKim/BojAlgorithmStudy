#include <iostream>

using namespace std;

int N, ans;
int Arr[15][15];

bool check(int row, int col) {
  for (int i = 0; i < row; i++)
    if (Arr[i][col]) return false;
  for (int i = 0; i < row; i++) {
    int y1 = col - (row - i);
    int y2 = col + (row - i);
    if (y1 < 0) {
      if (y2 >= N)
        continue;
      else {
        if (Arr[i][y2]) return false;
      }
    } else if (y2 >= N) {
      if (Arr[i][y1]) return false;
    } else {
      if (Arr[i][y1] || Arr[i][y2]) return false;
    }
  }
  return true;
}

void dfs(int d) {
  if (d == N)
    ans++;
  else {
    for (int i = 0; i < N; i++) {
      Arr[d][i] = 1;
      if (check(d, i)) dfs(d + 1);
      Arr[d][i] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  dfs(0);

  cout << ans << "\n";

  return 0;
}