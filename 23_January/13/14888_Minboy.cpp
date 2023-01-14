#include <iostream>

using namespace std;

int N;
int Arr[11];
int op[4];
int maxVal = -1'000'000'001;
int minVal = 1'000'000'001;

void dfs(int value, int d) {
  if (d == N - 1) {
    if (maxVal < value) maxVal = value;
    if (minVal > value) minVal = value;
  }
  for (int i = 0; i < 4; i++) {
    if (op[i]) {
      op[i]--;
      if (i == 0)
        dfs(value + Arr[d + 1], d + 1);
      else if (i == 1)
        dfs(value - Arr[d + 1], d + 1);
      else if (i == 2)
        dfs(value * Arr[d + 1], d + 1);
      else
        dfs(value / Arr[d + 1], d + 1);
      op[i]++;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];
  for (int i = 0; i < 4; i++) {
    cin >> op[i];
  }

  dfs(Arr[0], 0);

  cout << maxVal << "\n" << minVal << "\n";

  return 0;
}