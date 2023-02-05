#include <stdio.h>

int N, M;
int Arr[2020];
int dp[2020][2020];

int main(void) {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &Arr[i]);

  for (int i = 1; i <= N; i++) {
    dp[i][i] = 1;
    if (i == 1) continue;
    if (Arr[i - 1] == Arr[i]) dp[i - 1][i] = 1;
  }

  for (int i = 2; i <= N - 1; i++) {
    for (int j = 1; i + j <= N; j++) {
      if (Arr[j] == Arr[i + j] && dp[j + 1][i + j - 1] == 1) dp[j][i + j] = 1;
    }
  }

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int S, E;
    scanf("%d %d", &S, &E);
    printf("%d\n", dp[S][E]);
  }

  return 0;
}