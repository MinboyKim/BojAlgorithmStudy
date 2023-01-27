#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

vector<pair<int, int>> Edges[200'200];
int Visit[200'200];
int m, n, ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  while (true) {
    cin >> m >> n;
    if (m == 0 && n == 0) break;
    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c;
      ans += c;
      Edges[a].push_back({b, c});
      Edges[b].push_back({a, c});
    }

    Visit[0] = 1;
    for (auto &i : Edges[0]) pq.push(i);

    while (!pq.empty()) {
      pair<int, int> temp = pq.top();
      pq.pop();
      if (Visit[temp.first]) continue;
      Visit[temp.first] = 1;
      ans -= temp.second;
      for (auto &i : Edges[temp.first]) pq.push(i);
    }

    cout << ans << "\n";

    for (int i = 0; i < n; i++) {
      Visit[i] = 0;
      Edges[i].clear();
    }
    ans = 0;
  }

  return 0;
}