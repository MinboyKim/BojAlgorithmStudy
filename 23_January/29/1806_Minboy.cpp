#include <iostream>

using namespace std;

int N, S;
int Arr[100'101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  int l = 0, h = 0, sum = Arr[0], len = N + 1;

  while (l <= h && h < N) {
    if (sum < S) {
      h++;
      sum += Arr[h];
    } else {
      len = min(len, h - l + 1);
      l++;
      sum -= Arr[l - 1];
    }
  }

  if (len == N + 1)
    cout << 0 << "\n";
  else
    cout << len << "\n";

  return 0;
}