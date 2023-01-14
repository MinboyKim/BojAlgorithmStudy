#include <iostream>
#include <queue>

using namespace std;

int N, K;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    q;
int Visit[101010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  Visit[N] = 0;
  q.push({0, N});

  while (!q.empty()) {
    int curVertex = q.top().second;
    int curCost = q.top().first;
    q.pop();
    Visit[curVertex] = 1;
    if (curVertex == K) {
      cout << curCost << "\n";
      return 0;
    }
    if (curVertex - 1 >= 0 && !Visit[curVertex - 1])
      q.push({curCost + 1, curVertex - 1});
    if (curVertex + 1 <= 100000 && !Visit[curVertex + 1])
      q.push({curCost + 1, curVertex + 1});
    if (curVertex * 2 <= 100000 && !Visit[curVertex * 2])
      q.push({curCost, curVertex * 2});
  }

  return 0;
}