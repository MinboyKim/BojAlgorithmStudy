#include <limits.h>

#include <cstdlib>
#include <iostream>

using namespace std;

int N;
int Arr[101010];
int ans = INT_MAX;
int first, second;

void solve() {
  int l = 0;
  int r = N - 1;
  for (int i = 0; i < N - 1; i++) {
    int temp = Arr[l] + Arr[r];
    if (abs(temp) < ans && l < r) {
      ans = abs(temp);
      first = Arr[l];
      second = Arr[r];
    }
    if (temp < 0)
      l++;
    else if (temp > 0)
      r--;
    else if (temp == 0)
      break;
  }
  cout << first << " " << second << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
  }

  solve();

  return 0;
}