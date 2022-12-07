#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int N, M, ans;
int broken[11];

bool check(int a) {
  string s = to_string(a);
  for (int i = 0; i < s.length(); i++) {
    if (broken[int(s[i]) - 48]) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    broken[a] = 1;
  }

  ans = abs(N - 100);

  int up = N;
  int count = 0;
  while (up < 1000010) {
    if (check(up)) {
      ans = min(ans, (int)(to_string(up).length() + count));
      break;
    }
    up++;
    count++;
  }

  int down = N - 1;
  count = 1;
  while (down >= 0) {
    if (check(down)) {
      ans = min(ans, (int)(to_string(down).length() + count));
      break;
    }
    down--;
    count++;
  }

  cout << ans << "\n";

  return 0;
}