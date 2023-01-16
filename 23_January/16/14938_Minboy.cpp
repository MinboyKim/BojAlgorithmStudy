#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, r, ans;
vector<pair<int, int>> Edges[111];
int Vertex[111];
int dist[111];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

void dijkstra(int s) {
  dist[s] = 0;
  pq.push({0, s});
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
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, l, temp;
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) cin >> Vertex[i];
  for (int i = 0; i < r; i++) {
    cin >> a >> b >> l;
    Edges[a].push_back({b, l});
    Edges[b].push_back({a, l});
  }

  for (int i = 1; i <= n; i++) {
    temp = 0;
    for (int j = 1; j <= n; j++) dist[j] = 999'999'999;
    dijkstra(i);
    for (int j = 1; j <= n; j++) {
      if (dist[j] <= m) {
        temp += Vertex[j];
      }
    }
    if (temp > ans) ans = temp;
  }

  cout << ans << "\n";

  return 0;
}