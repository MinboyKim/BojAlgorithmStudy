#include <cstring>
#include <iostream>

using namespace std;

int N, M, K, ans;
int Arr[111][111];
int Visit[111][111];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

int dfs(int row, int col) {
  int ret = 1;
  Visit[row][col] = 1;
  for (int i = 0; i < 4; i++) {
    int x = row + diff[1][i];
    int y = col + diff[0][i];
    if (x < 0 || y < 0 || x >= N || y >= M) continue;
    if (Visit[x][y]) continue;
    if (Arr[x][y]) ret = ret + dfs(x, y);
  }
  return ret;
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (Arr[i][j] && !Visit[i][j]) {
        ans = max(ans, dfs(i, j));
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    Arr[a - 1][b - 1] = 1;
  }

  solve();

  cout << ans << "\n";

  return 0;
}