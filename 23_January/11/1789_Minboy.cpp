#include <iostream>

using namespace std;

long S;

bool check(long t) {
  long long sum = 0;
  for (long i = 1; i <= t; i++) {
    sum += i;
  }
  if (sum <= S)
    return true;
  else
    return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> S;

  long l = 1, r = S;
  while (l + 1 < r) {
    long mid = (l + r) / 2;
    if (check(mid) == check(l))
      l = mid;
    else
      r = mid;
  }

  cout << l << "\n";

  return 0;
}