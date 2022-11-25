#include <iostream>
#include <string>

using namespace std;

int N;

bool check(string s) {
  for (int i = 0; i <= s.length() - 3; i++) {
    if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6') return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int number = 665;
  int ans = 0;
  cin >> N;
  while (true) {
    number++;
    string s = to_string(number);
    if (check(s)) {
      N--;
      if (!N) {
        ans = number;
        break;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}