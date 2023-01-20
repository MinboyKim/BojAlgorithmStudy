#include <iostream>

using namespace std;

int N, ans;
int Arr[20][20];

void dfs(int r, int c, int dir) {
  if (r == N && c == N) {
    ans++;
    return;
  }
  int nr = 0, nc = 0, ndir = 0;
  if (dir == 0) {
    nr = r + 0;
    nc = c + 1;
    ndir = 0;
    if (nr > 0 && nc > 0 && nr <= N && nc <= N && !Arr[nr][nc])
      dfs(nr, nc, ndir);
    nr = r + 1;
    nc = c + 1;
    ndir = 2;
    if (nr > 0 && nc > 0 && nr <= N && nc <= N && !Arr[nr][nc - 1] &&
        !Arr[nr - 1][nc] && !Arr[nr][nc])
      dfs(nr, nc, ndir);
  } else if (dir == 1) {
    nr = r + 1;
    nc = c + 0;
    ndir = 1;
    if (nr > 0 && nc > 0 && nr <= N && nc <= N && !Arr[nr][nc])
      dfs(nr, nc, ndir);
    nr = r + 1;
    nc = c + 1;
    ndir = 2;
    if (nr > 0 && nc > 0 && nr <= N && nc <= N && !Arr[nr][nc - 1] &&
        !Arr[nr - 1][nc] && !Arr[nr][nc])
      dfs(nr, nc, ndir);
  } else {
    nr = r + 0;
    nc = c + 1;
    ndir = 0;
    if (nr > 0 && nc > 0 && nr <= N && nc <= N && !Arr[nr][nc])
      dfs(nr, nc, ndir);
    nr = r + 1;
    nc = c + 0;
    ndir = 1;
    if (nr > 0 && nc > 0 && nr <= N && nc <= N && !Arr[nr][nc])
      dfs(nr, nc, ndir);
    nr = r + 1;
    nc = c + 1;
    ndir = 2;
    if (nr > 0 && nc > 0 && nr <= N && nc <= N && !Arr[nr][nc - 1] &&
        !Arr[nr - 1][nc] && !Arr[nr][nc])
      dfs(nr, nc, ndir);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> Arr[i][j];
    }
  }

  dfs(1, 2, 0);

  cout << ans << "\n";

  return 0;
}