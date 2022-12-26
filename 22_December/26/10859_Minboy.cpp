#include <iostream>
#include <string>

using namespace std;

long long N;

bool isPrime(long long t) {
  if (t == 1) return false;
  for (long long i = 2; i * i <= t; i++)
    if (t % i == 0) return false;
  return true;
}

long long flip(long long t) {
  long long ret = 0;
  while (t > 0) {
    if (t % 10 == 6) {
      ret = ret * 10 + 9;
    } else if (t % 10 == 9) {
      ret = ret * 10 + 6;
    } else {
      ret = ret * 10 + t % 10;
    }
    t = t / 10;
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  long long temp = N;
  while (temp > 0) {
    if (temp % 10 == 3 || temp % 10 == 4 || temp % 10 == 7) {
      cout << "no\n";
      return 0;
    }
    temp = temp / 10;
  }

  if (isPrime(N) && isPrime(flip(N)))
    cout << "yes\n";
  else
    cout << "no\n";

  return 0;
}