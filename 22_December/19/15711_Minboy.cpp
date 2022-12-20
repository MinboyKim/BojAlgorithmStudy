#include <iostream>
#include <vector>

using namespace std;

int T;
long long A, B;
vector<int> prime;
int table[2'000'002];

bool isPrime(long long p) {
  for (int i = 0; prime[i] * prime[i] <= p && i < prime.size(); i++) {
    if (p % prime[i] == 0) return false;
  }
  return true;
}

void solve() {
  long long sum = A + B;
  if (sum <= 3)
    cout << "NO\n";
  else if (sum % 2 == 0)
    cout << "YES\n";
  else {
    if (isPrime(sum - 2))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  table[0] = 1;
  table[1] = 1;
  for (int i = 2; i * i < 2'000'002; i++) {
    if (!table[i]) {
      for (int j = i * i; j < 2'000'002; j += i) {
        table[j] = 1;
      }
    }
  }
  for (int i = 0; i < 2'000'002; i++)
    if (!table[i]) prime.push_back(i);

  cin >> T;
  while (T--) {
    cin >> A >> B;
    solve();
  }

  return 0;
}