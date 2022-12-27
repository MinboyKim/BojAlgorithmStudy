#include <deque>
#include <iostream>
#include <string>

using namespace std;

int ans = 999999;
bool flag = true;
string s1, s2;
deque<char> d1;
deque<char> d2;

void solve() {
  if (s1.length() > s2.length()) swap(s1, s2);
  for (int i = 0; i < s1.length(); i++) d1.push_back(s1[i]);
  for (int i = 0; i < s1.length() + s2.length() - 2; i++) d1.push_back('0');
  for (int i = 0; i < s2.length(); i++) d2.push_back(s2[i]);
  for (int i = 0; i < s1.length() - 1; i++) {
    d2.push_back('0');
    d2.push_front('0');
  }

  for (int i = 0; i < s2.length() + s1.length() - 1; i++) {
    for (int j = 0; j < s2.length() + (s1.length() * 2) - 2; j++) {
      if (d1[j] == '2' && d2[j] == '2') {
        flag = false;
        break;
      }
    }
    if (flag) {
      int count = 0;
      for (int j = 0; j < s2.length() + (s1.length() * 2) - 2; j++) {
        if (d1[j] != '0' || d2[j] != '0') count++;
      }
      ans = min(ans, count);
    }
    d1.pop_back();
    d1.push_front('0');
    flag = true;
  }
  ans = min(ans, (int)(s1.length() + s2.length()));
  cout << ans << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s1 >> s2;

  solve();

  return 0;
}