#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int T;
int big[4];
int small[4];

void solve() {
  int count = 0;
  string s;
  cin >> s;
  while (true) {
    if (s == "6174") {
      cout << count << "\n";
      return;
    }
    for (int i = 0; i < 4; i++) {
      big[i] = int(s[i] - 48);
      small[i] = int(s[i] - 48);
    }
    sort(big, big + 4, greater<>());
    sort(small, small + 4);
    int bigInt = 1000 * big[0] + 100 * big[1] + 10 * big[2] + big[3];
    int smallInt = 1000 * small[0] + 100 * small[1] + 10 * small[2] + small[3];
    int temp = bigInt - smallInt;
    s = to_string(temp);
    if (s.length() != 4) {
      s = '0' * (4 - s.length());
      s += to_string(temp);
    }
    count++;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}