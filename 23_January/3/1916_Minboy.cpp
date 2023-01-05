#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> Edges[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int dist[1010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    Edges[a].push_back({b, c});
  }

  for (int i = 1; i <= N; i++) dist[i] = 900'000'000;
  cin >> a >> b;
  dist[a] = 0;
  pq.push({0, a});

  while (!pq.empty()) {
    int curCost = pq.top().first;
    int curVertex = pq.top().second;
    pq.pop();
    if (curCost > dist[curVertex]) continue;
    for (auto &i : Edges[curVertex]) {
      int nextCost = i.second;
      int nextVertex = i.first;
      if (curCost + nextCost < dist[nextVertex]) {
        dist[nextVertex] = curCost + nextCost;
        pq.push({curCost + nextCost, nextVertex});
      }
    }
  }

  cout << dist[b] << "\n";

  return 0;
}