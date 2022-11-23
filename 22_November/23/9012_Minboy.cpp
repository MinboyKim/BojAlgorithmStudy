#include <iostream>
#include <stack>

using namespace std;

int T;
string s;
stack<char> stk;

void solve() {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      stk.push(s[i]);
    else {
      if (!stk.empty())
        stk.pop();
      else {
        cout << "NO\n";
        return;
      }
    }
  }
  if (!stk.empty()) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  return;
}

int main(void) {
  cin >> T;
  while (T--) {
    cin >> s;
    solve();
    while (!stk.empty()) stk.pop();
  }

  return 0;
}