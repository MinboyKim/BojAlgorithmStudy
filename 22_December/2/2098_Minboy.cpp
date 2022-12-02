#include <limits.h>

#include <iostream>

using namespace std;

int N;
int W[16][16];
int dp[16][1 << 16];

int AV;

int solve(int current, int visited) {
  if (visited == AV) {
    if (W[current][0] > 0) {
      return W[current][0];
    }
    return 1000000000;
  }
  if (dp[current][visited] != 0) return dp[current][visited];

  dp[current][visited] = 1000000000;

  for (int i = 0; i < N; i++) {
    if (W[current][i] == 0) continue;
    if (visited & (1 << i)) continue;
    int temp = solve(i, visited | (1 << i));
    dp[current][visited] = min(dp[current][visited], W[current][i] + temp);
  }

  return dp[current][visited];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  AV = (1 << N) - 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> W[i][j];
    }
  }

  cout << solve(0, 1) << "\n";

  return 0;
}