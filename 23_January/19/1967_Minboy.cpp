#include <iostream>
#include <vector>

using namespace std;

int n, node, ans;
vector<pair<int, int>> Edges[10010];
int Visit[10010];

void dfs(int v, int sum) {
  if (sum > ans) {
    ans = sum;
    node = v;
  }
  for (auto &i : Edges[v]) {
    if (!Visit[i.first]) {
      Visit[i.first] = 1;
      dfs(i.first, sum + i.second);
      Visit[i.first] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    Edges[a].push_back({b, c});
    Edges[b].push_back({a, c});
  }

  Visit[1] = 1;
  dfs(1, 0);

  for (int i = 1; i <= n; i++) Visit[i] = 0;
  Visit[node] = 1;
  dfs(node, 0);

  cout << ans << "\n";

  return 0;
}