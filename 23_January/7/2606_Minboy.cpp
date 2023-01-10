#include <iostream>
#include <vector>

using namespace std;

int V, E, ans;
vector<int> Edges[111];
int Visit[111];

int dfs(int p) {
  Visit[p] = 1;
  int ret = 1;
  for (auto &i : Edges[p]) {
    if (!Visit[i]) ret += dfs(i);
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    cin >> a >> b;
    Edges[a].push_back(b);
    Edges[b].push_back(a);
  }

  ans = dfs(1);
  cout << ans - 1 << "\n";

  return 0;
}