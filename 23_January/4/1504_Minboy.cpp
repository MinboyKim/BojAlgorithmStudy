#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 999'999'999;
int N, E, V1, V2, ans;
vector<pair<int, int>> Edges[808];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int dist[3][808];

void dijkstra(int id, int start) {
  dist[id][start] = 0;
  pq.push({0, start});
  while (!pq.empty()) {
    int curCost = pq.top().first;
    int curVertex = pq.top().second;
    pq.pop();
    if (curCost > dist[id][curVertex]) continue;
    for (auto &i : Edges[curVertex]) {
      int nextCost = i.second;
      int nextVertex = i.first;
      if (dist[id][nextVertex] > curCost + nextCost) {
        dist[id][nextVertex] = curCost + nextCost;
        pq.push({curCost + nextCost, nextVertex});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> N >> E;
  for (int i = 1; i <= N; i++) {
    dist[0][i] = MAX;
    dist[1][i] = MAX;
    dist[2][i] = MAX;
  }
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    Edges[a].push_back({b, c});
    Edges[b].push_back({a, c});
  }
  cin >> V1 >> V2;
  dijkstra(0, 1);
  dijkstra(1, V1);
  dijkstra(2, V2);

  if (dist[0][V1] == MAX || dist[1][V2] == MAX || dist[2][N] == MAX ||
      dist[0][V2] == MAX || dist[1][N] == MAX) {
    cout << -1 << "\n";
    return 0;
  }

  ans = dist[0][V1] + dist[1][V2] + dist[2][N];
  ans = min(ans, dist[0][V2] + dist[2][V1] + dist[1][N]);
  cout << ans << "\n";

  return 0;
}