#include <iostream>
#include <set>
#include <vector>

using namespace std;

int T, N;

vector<int> x[202020];
set<int> y;

bool solve() {
  for (int i = 0; i < N; i++) {
    if (x[i].size() != 0 && x[i].size() != y.size()) return false;
  }
  return true;
}

int main(void) {
  int a, b;
  cin >> T;
  while (T--) {
    cin >> N;
    cin >> a >> b;
    for (int i = 0; i < N; i++) {
      x[i].push_back(b);
      y.insert(b);
    }
    solve();
    for (int i = 0; i < N; i++) {
      x[i].clear();
    }
    y.clear();
  }

  return 0;
}