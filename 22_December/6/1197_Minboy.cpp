#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

int V, E, ans;
int Visit[10'101];
vector<pair<int, int>> Vertex[101'010];
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> PQ;

void solve(int root) {
  Visit[root] = 1;
  for (auto& i : Vertex[root]) PQ.push(i);
  while (!PQ.empty()) {
    pair<int, int> temp = PQ.top();
    PQ.pop();
    if (!Visit[temp.first]) {
      Visit[temp.first] = 1;
      ans += temp.second;
    }
    for (auto& i : Vertex[temp.first]) {
      if (!Visit[i.first]) PQ.push(i);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int A, B, C;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    cin >> A >> B >> C;
    Vertex[A].push_back({B, C});
    Vertex[B].push_back({A, C});
  }

  solve(A);

  cout << ans << "\n";

  return 0;
}