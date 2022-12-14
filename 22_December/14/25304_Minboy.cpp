#include <iostream>

using namespace std;

int X, N, sum;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> X >> N;
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    sum += a * b;
  }
  if (sum == X)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}