#include <iostream>
#include <queue>

using namespace std;

long long A, B, ans;
queue<pair<long long, int>> q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> A >> B;
  q.push({A, 0});
  while (!q.empty()) {
    pair<long long, int> temp = q.front();
    q.pop();
    if (temp.first == B) {
      ans = temp.second + 1;
      cout << ans << "\n";
      return 0;
    }

    if (temp.first * 2 <= B) {
      q.push({temp.first * 2, temp.second + 1});
    }
    if (temp.first * 10 + 1 <= B) {
      q.push({temp.first * 10 + 1, temp.second + 1});
    }
  }

  cout << -1 << "\n";

  return 0;
}