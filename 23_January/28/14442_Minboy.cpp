#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
  int x;
  int y;
  int result;
  int wall;
} pt;

int N, M, K;
int matrix[1010][1010];
int Visit[1010][1010][11];
int diff[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};  // right, left, down, up
queue<pt> q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    cin >> s;
    for (int j = 1; j <= M; j++) {
      matrix[i][j] = s[j - 1] - '0';
    }
  }

  q.push({1, 1, 1, 0});
  for (int i = 0; i < 11; i++) Visit[1][1][i] = 1;

  while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int result = q.front().result;
    int wall = q.front().wall;
    q.pop();

    if (x == N && y == M) {
      cout << result << "\n";
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int dx = x + diff[0][i];
      int dy = y + diff[1][i];

      if (dx < 1 || dy < 1 || dx > N || dy > M) continue;

      if (!Visit[dx][dy][wall]) {
        if (!matrix[dx][dy]) {
          Visit[dx][dy][wall] = 1;
          q.push({dx, dy, result + 1, wall});
        } else {  // matrix[dx][dy] == 1
          if (wall < K) {
            if (!Visit[dx][dy][wall + 1]) {
              Visit[dx][dy][wall + 1] = 1;
              q.push({dx, dy, result + 1, wall + 1});
            }
          }
        }
      }
    }
  }

  cout << -1 << "\n";

  return 0;
}