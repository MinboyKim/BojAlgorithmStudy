#include <iostream>
#include <queue>
#include <vector>

#define MAX 99'999'999;

using namespace std;

int N, M, X, ans;
vector<pair<int, int>> Edges[2][1010];  // Edges[0] : forward, Edges[1] :
                                        // reverse
int dist[2][1010];  // dist[0] : forward, dist[1] : reverse
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

void dijkstra(int id) {  // dijkstra algorithm
  dist[id][X] = 0;

  pq.push({0, X});
  while (!pq.empty()) {
    int curCost = pq.top().first;
    int curVertex = pq.top().second;
    pq.pop();
    if (curCost > dist[id][curVertex]) continue;
    for (auto &i : Edges[id][curVertex]) {
      int nextCost = i.second;
      int nextVertex = i.first;
      if (curCost + nextCost < dist[id][nextVertex]) {
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
  cin >> N >> M >> X;

  for (int i = 1; i <= N; i++) {  // initialize
    dist[0][i] = MAX;
    dist[1][i] = MAX;
  }

  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    Edges[0][a].push_back({b, c});  // forward graph
    Edges[1][b].push_back({a, c});  // reverse graph
  }

  dijkstra(0);
  dijkstra(1);

  for (int i = 1; i <= N; i++)  // find max value
    if (dist[0][i] + dist[1][i] > ans) ans = dist[0][i] + dist[1][i];

  cout << ans << "\n";

  return 0;
}