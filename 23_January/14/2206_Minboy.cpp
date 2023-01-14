#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef struct {
  int x;
  int y;
  int wall;
} pt;

int N, M;
int map[1010][1010];
int result[1010][1010];
int Visit[1010][1010][2];
queue<pt> q;
int diff[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= M; j++) map[i][j] = s[j - 1] - '0';
  }

  q.push({1, 1, 0});
  Visit[1][1][0] = 1;
  Visit[1][1][1] = 1;
  result[1][1] = 1;

  while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int wall = q.front().wall;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int dx = x + diff[0][i];
      int dy = y + diff[1][i];
      if (dx < 1 || dy < 1 || dx > N || dy > M) continue;

      if (map[dx][dy] == 1 && wall == 0 && !Visit[dx][dy][1]) {
        Visit[dx][dy][1] = 1;
        result[dx][dy] = result[x][y] + 1;
        q.push({dx, dy, 1});
      } else if (map[dx][dy] == 0 && !Visit[dx][dy][wall]) {
        Visit[dx][dy][wall] = 1;
        result[dx][dy] = result[x][y] + 1;
        q.push({dx, dy, wall});
      }
      if (dx == N && dy == M) {
        cout << result[dx][dy] << "\n";
        return 0;
      }
    }
  }

  if (N == 1 && M == 1)
    cout << 1 << "\n";
  else
    cout << -1 << "\n";

  return 0;
}