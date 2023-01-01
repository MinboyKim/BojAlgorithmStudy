#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int N, M, ans;
vector<pair<int, int>> Edges[1010];
int Visit[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    Edges[a].push_back({b, c});
    Edges[b].push_back({a, c});
  }

  Visit[a] = 1;
  for (auto &i : Edges[a]) pq.push(i);

  while (!pq.empty()) {
    pair<int, int> temp = pq.top();
    pq.pop();
    if (Visit[temp.first]) continue;
    ans += temp.second;
    Visit[temp.first] = 1;
    for (auto &i : Edges[temp.first]) pq.push(i);
  }

  cout << ans << "\n";

  return 0;
}