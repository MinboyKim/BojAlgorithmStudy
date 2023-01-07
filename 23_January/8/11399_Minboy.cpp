#include <algorithm>
#include <iostream>

using namespace std;

int N, ans;
int Arr[1111];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  sort(Arr, Arr + N);

  ans += Arr[0];
  for (int i = 1; i < N; i++) {
    Arr[i] += Arr[i - 1];
    ans += Arr[i];
  }

  cout << ans << "\n";

  return 0;
}