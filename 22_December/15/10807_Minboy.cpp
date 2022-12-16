#include <iostream>

using namespace std;

int N, v, ans;
int Arr[111];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
  }
  cin >> v;
  for (int i = 0; i < N; i++)
    if (Arr[i] == v) ans++;
  cout << ans << "\n";

  return 0;
}