#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E, K;
vector<pair<int, int>> Edges[20202];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int dist[20202];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> V >> E >> K;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    Edges[a].push_back({b, c});
  }

  for (int i = 1; i <= V; i++) dist[i] = 9'999'999;

  dist[K] = 0;

  pq.push({0, K});

  while (!pq.empty()) {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    for (auto &i : Edges[cur]) {
      int tempV = i.first;
      int tempCost = i.second;
      if (cost + tempCost < dist[tempV]) {
        dist[tempV] = cost + tempCost;
        pq.push({cost + tempCost, tempV});
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if (dist[i] < 9'999'999)
      cout << dist[i] << "\n";
    else
      cout << "INF\n";
  }

  return 0;
}