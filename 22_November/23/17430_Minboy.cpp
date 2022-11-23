#include <iostream>
#include <set>

using namespace std;

int T, N;
set<int> x;
set<int> y;

void solve() {
  int a, b;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }
  if (x.size() * y.size() == N)
    cout << "BALANCED\n";
  else
    cout << "NOT BALANCED\n";
  x.clear();
  y.clear();
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}