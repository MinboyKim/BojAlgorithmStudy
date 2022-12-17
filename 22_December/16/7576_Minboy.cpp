#include <iostream>
#include <queue>

using namespace std;

int M, N, ans;
int Arr[1010][1010];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

queue<pair<int, int>> q;

void solve() {
  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x = temp.first - diff[0][i];
      int y = temp.second - diff[1][i];
      if (x < 0 || y < 0 || x >= M || y >= N) continue;
      if (Arr[x][y] == 0) {
        Arr[x][y] = Arr[temp.first][temp.second] + 1;
        q.push({x, y});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> Arr[i][j];
      if (Arr[i][j] == 1) {
        q.push({i, j});
      }
    }
  }

  solve();

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (Arr[i][j] == 0) {
        cout << -1 << "\n";
        return 0;
      }
      if (ans < Arr[i][j]) ans = Arr[i][j];
    }
  }
  cout << ans - 1 << "\n";

  return 0;
}