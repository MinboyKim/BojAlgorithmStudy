#include <cstring>
#include <iostream>

using namespace std;

int M, N;
int puzzle[10][10];
int Visit[10][10];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

void fall() {
  for (int i = 0; i < N - 1; i++) {
    for (int j = N - 2; j >= 0; j--) {
      for (int k = 0; k < M; k++) {
        if (puzzle[j][k] && puzzle[j + 1][k] == 0) {
          puzzle[j + 1][k] = puzzle[j][k];
          puzzle[j][k] = 0;
        }
      }
    }
  }
}

int dfs(int row, int col, int c) {
  Visit[row][col] = 1;
  int ret = 1;
  puzzle[row][col] = 0;
  for (int i = 0; i < 4; i++) {
    int x = row + diff[0][i];
    int y = col + diff[1][i];
    if (x < 0 || y < 0 || x >= N || y >= M) continue;
    if (Visit[x][y]) continue;
    if (c == puzzle[x][y]) ret += dfs(x, y, c);
  }
  return ret;
}

int solve(int depth) {
  if (!depth) return 0;
  int save[10][10];
  int ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      save[i][j] = puzzle[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (puzzle[i][j] > 0) {
        memset(Visit, 0, sizeof(Visit));
        int point = dfs(i, j, puzzle[i][j]);
        fall();
        ret = max(ret, point * point + solve(depth - 1));
        for (int k = 0; k < N; k++) {
          for (int l = 0; l < M; l++) {
            puzzle[k][l] = save[k][l];
          }
        }
      }
    }
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> M >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> puzzle[i][j];
    }
  }

  cout << solve(3) << "\n";

  return 0;
}