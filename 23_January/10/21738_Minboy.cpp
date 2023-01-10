#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, S, P;
int cnt, first, second;
vector<int> Edges[328005];
queue<pair<int, int>> q;
int Visit[328005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> N >> S >> P;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    Edges[a].push_back(b);
    Edges[b].push_back(a);
  }

  Visit[P] = 1;
  for (auto &i : Edges[P]) q.push({i, 1});
  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();
    Visit[temp.first] = 1;
    if (temp.first <= S) {
      if (!first)
        first = temp.second;
      else {
        second = temp.second;
        break;
      }
    } else {
      for (auto &i : Edges[temp.first]) {
        if (!Visit[i]) q.push({i, temp.second + 1});
      }
    }
  }

  cout << N - first - second - 1 << "\n";

  return 0;
}