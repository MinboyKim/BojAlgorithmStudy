#include <iostream>

using namespace std;

int N, M;
int Select[10];

void dfs(int d, int pos) {
  if (d == M + 1) {
    for (int i = 1; i <= N; i++) {
      if (Select[i]) cout << i << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = pos; i <= N; i++) {
    Select[i] = 1;
    dfs(d + 1, i + 1);
    Select[i] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  dfs(1, 1);

  return 0;
}