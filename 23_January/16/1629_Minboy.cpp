#include <iostream>

using namespace std;

long long A, B, C;

long long solve(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long temp = solve(a, b / 2) % C;
  if (b % 2 == 0)
    return (temp * temp) % C;
  else
    return (((temp * temp) % C) * a) % C;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> A >> B >> C;

  cout << solve(A, B) % C << "\n";

  return 0;
}