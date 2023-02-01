#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
long long ans;
vector<pair<int, int>> Edges[1010];
int Visit[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a;
      if (a == 0) continue;
      Edges[i].push_back({a, j});
      Edges[j].push_back({a, i});
    }
  }

  Visit[1] = 1;
  for (auto &i : Edges[1]) pq.push(i);

  while (!pq.empty()) {
    pair<int, int> temp = pq.top();
    pq.pop();
    if (Visit[temp.second]) continue;
    Visit[temp.second] = 1;
    ans += temp.first;
    for (auto &i : Edges[temp.second]) pq.push(i);
  }

  cout << ans << "\n";

  return 0;
}