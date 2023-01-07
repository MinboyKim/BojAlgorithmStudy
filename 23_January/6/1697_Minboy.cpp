#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
queue<pair<int, int>> q;
int Visit[201'010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  Visit[N] = 1;
  q.push({0, N});
  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();
    if (temp.second == K) {
      cout << temp.first << "\n";
      return 0;
    }
    if (!Visit[temp.second - 1] && temp.second > 0) {
      Visit[temp.second - 1] = 1;
      q.push({temp.first + 1, temp.second - 1});
    }
    if (!Visit[temp.second + 1] && temp.second < 100'000) {
      Visit[temp.second + 1] = 1;
      q.push({temp.first + 1, temp.second + 1});
    }
    if (!Visit[temp.second * 2] && temp.second < 50'001) {
      Visit[temp.second * 2] = 1;
      q.push({temp.first + 1, temp.second * 2});
    }
  }

  return 0;
}