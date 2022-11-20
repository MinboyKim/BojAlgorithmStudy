#include <iostream>
#include <string>
using namespace std;

string p;

void solve() {
  int l = p.length();
  for (int i = 0; i <= (l / 2); i++) {
    if (p[i] == p[l - i - 1])
      continue;
    else {
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
}

int main(void) {
  while (true) {
    cin >> p;
    if (p == "0") break;
    solve();
  }

  return 0;
}