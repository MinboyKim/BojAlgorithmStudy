#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int N, M, maxEdge, ans;
vector<pair<int, int>> Edges[101'010];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
int Visit[101'010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int A, B, C;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    Edges[A].push_back({B, C});
    Edges[B].push_back({A, C});
  }

  Visit[A] = 1;
  for (auto &i : Edges[A]) pq.push(i);

  while (!pq.empty()) {
    pair<int, int> temp = pq.top();
    pq.pop();
    if (Visit[temp.first]) continue;
    Visit[temp.first] = 1;
    ans += temp.second;
    maxEdge = max(maxEdge, temp.second);
    for (auto &i : Edges[temp.first]) pq.push(i);
  }

  cout << ans - maxEdge << "\n";

  return 0;
}