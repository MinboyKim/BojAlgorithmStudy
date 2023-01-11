#include <iostream>

using namespace std;

int N, ans1, ans2;
char Arr[111][111];
int Visit[111][111];
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

void dfs1(char c, int row, int col) {
  Visit[row][col] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = row + diff[0][i];
    int ny = col + diff[1][i];
    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
    if (!Visit[nx][ny] && Arr[nx][ny] == c) dfs1(c, nx, ny);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!Visit[i][j]) {
        ans1++;
        dfs1(Arr[i][j], i, j);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (Arr[i][j] == 'G') Arr[i][j] = 'R';
      Visit[i][j] = 0;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!Visit[i][j]) {
        ans2++;
        dfs1(Arr[i][j], i, j);
      }
    }
  }

  cout << ans1 << " " << ans2 << "\n";

  return 0;
}