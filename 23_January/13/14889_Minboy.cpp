#include <cmath>
#include <iostream>

using namespace std;

int N;
int team[22];
int S[22][22];
int ans = 999'999'999;

void dfs(int d, int next) {
  if (d == N / 2) {
    int start = 0;
    int link = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (team[i] == 0 && team[j] == 0) start += S[i][j];
        if (team[i] == 1 && team[j] == 1) link += S[i][j];
      }
    }
    int temp = abs(start - link);
    if (ans > temp) ans = temp;
    return;
  }
  for (int i = next; i < N; i++) {
    team[i] = 1;
    dfs(d + 1, i + 1);
    team[i] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> S[i][j];
  }

  dfs(0, 0);

  cout << ans << "\n";

  return 0;
}