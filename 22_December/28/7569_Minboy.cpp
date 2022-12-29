#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H, ans;
int box[111][111][111];
int Visited[111][111][111];
queue<tuple<int, int, int>> q;
int diff[3][6] = {
    {-1, 1, 0, 0, 0, 0}, {0, 0, -1, 1, 0, 0}, {0, 0, 0, 0, -1, 1}};

void bfs(int h, int r, int c) {
  for (int i = 0; i < 6; i++) {
    int dh = h + diff[0][i];
    int dr = r + diff[1][i];
    int dc = c + diff[2][i];
    if (dh < 0 || dr < 0 || dc < 0 || dh >= H || dr >= N || dc >= M) continue;
    if (Visited[dh][dr][dc] == 1) continue;
    if (box[dh][dr][dc] == 0) {
      box[dh][dr][dc] = box[h][r][c] + 1;
      Visited[dh][dr][dc] = 1;
      q.push({dh, dr, dc});
    }
  }
}

void solve() {
  while (!q.empty()) {
    int h = get<0>(q.front());
    int r = get<1>(q.front());
    int c = get<2>(q.front());
    q.pop();
    bfs(h, r, c);
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (box[i][j][k] == 0) {
          cout << -1 << "\n";
          return;
        }
        if (ans < box[i][j][k]) ans = box[i][j][k];
      }
    }
  }

  cout << ans - 1 << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> M >> N >> H;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        cin >> box[i][j][k];
        if (box[i][j][k] == 1) {
          q.push({i, j, k});
          Visited[i][j][k] = 1;
        }
      }
    }
  }

  solve();

  return 0;
}