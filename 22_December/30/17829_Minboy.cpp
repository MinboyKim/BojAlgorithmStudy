#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int N;
int Matrix[1030][1030];

int myMin(int a, int b, int c, int d) {  // return second largest value
  int Arr[4] = {a, b, c, d};
  sort(Arr, Arr + 4);
  return Arr[2];
}

int solve(int row, int col, int size) {    // recursive
  if (size == 1) return Matrix[row][col];  // termination condition
  int p = size / 2;
  int a = solve(row, col, p);
  int b = solve(row, col + p, p);
  int c = solve(row + p, col, p);
  int d = solve(row + p, col + p, p);
  return myMin(a, b, c, d);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> Matrix[i][j];
  cout << solve(0, 0, N) << "\n";

  return 0;
}