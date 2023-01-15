#include <iostream>
#include <vector>

using namespace std;

int V, node, ans;
vector<pair<int, int>> Edges[101010];
int Visit[101010];

void dfs(int curNode, int sum) {
  if (sum > ans) {
    ans = sum;
    node = curNode;
  }
  for (auto &i : Edges[curNode]) {
    if (!Visit[i.second]) {
      Visit[i.second] = 1;
      dfs(i.second, sum + i.first);
      Visit[i.second] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V;
  for (int i = 0; i < V; i++) {
    int num = 0;
    cin >> num;
    int a = 0;
    while (true) {
      cin >> a;
      if (a == -1) break;
      int b;
      cin >> b;
      Edges[num].push_back({b, a});
    }
  }
  Visit[1] = 1;
  dfs(1, 0);

  for (int i = 1; i <= V; i++) Visit[i] = 0;
  ans = 0;
  Visit[node] = 1;
  dfs(node, 0);

  cout << ans << "\n";

  return 0;
}