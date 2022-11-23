#include <iostream>
#include <stack>

using namespace std;

string T;
stack<char> st;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  bool leaf_check = false;
  long long ans = 0;
  for (int i = 0; i < T.length(); i++) {
    if (T[i] == '(') {
      st.push('(');
      leaf_check = true;
    } else {
      st.pop();
      if (leaf_check) {
        ans += st.size();
      }
      leaf_check = false;
    }
  }
  cout << ans << "\n";

  return 0;
}