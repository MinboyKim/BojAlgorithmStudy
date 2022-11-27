#include <iostream>

using namespace std;

int N;
int memo[101010] = {0, 1, 1, 2, 2, 1, 2, 1};

int myMin(int a, int b, int c, int d) {
  int temp[4] = {a, b, c, d};
  int minimum = 99999999;
  for (int i = 0; i < 4; i++) {
    if (minimum > temp[i]) minimum = temp[i];
  }
  return minimum;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 8; i <= N; i++) {
    memo[i] = myMin(memo[i - 1] + 1, memo[i - 2] + 1, memo[i - 5] + 1,
                    memo[i - 7] + 1);
  }
  cout << memo[N] << "\n";

  return 0;
}