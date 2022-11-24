#include <iostream>

using namespace std;

int N, M;
string Board1[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                    "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string Board2[8] = {
    "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
    "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
};
string uBoard[50];

int B1_check(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (Board1[i][j] != uBoard[x + i][y + j]) cnt++;
    }
  }
  return cnt;
}
int B2_check(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (Board2[i][j] != uBoard[x + i][y + j]) cnt++;
    }
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  int ans = INT_MAX;

  for (int i = 0; i < N; i++) {
    cin >> uBoard[i];
  }

  for (int i = 0; i <= N - 8; i++) {
    for (int j = 0; j <= M - 8; j++) {
      int temp = min(B1_check(i, j), B2_check(i, j));
      if (ans > temp) ans = temp;
    }
  }

  cout << ans << "\n";

  return 0;
}