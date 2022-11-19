#include <iostream>
#include <vector>

using namespace std;

int V, E, dfn, cnt = 0;
vector<int> Edge[101010];
vector<int> Type[101010];
int L[101010];
int Cut[101010];
int Dfn[101010];

void dfs(int x, int p) {
  Dfn[x] = ++dfn;
  for (int i = 0; i < Edge[x].size(); i++) {
    if (Edge[x][i] == p)
      Type[x][i] = 1;
    else if (Dfn[Edge[x][i]] == 0) {
      Type[x][i] = 2;
      dfs(Edge[x][i], x);
    } else {
      Type[x][i] = 3;
    }
  }
}

int dfs2(int x, int p) {
  int rv, cc;
  L[x] = Dfn[x];
  for (int i = 0; i < Edge[x].size(); i++) {
    if (Type[x][i] == 1)
      ;
    else if (Type[x][i] == 2) {
      rv = dfs2(Edge[x][i], x);
      L[x] = min(L[x], rv);
    } else {
      L[x] = min(L[x], Dfn[Edge[x][i]]);
    }
  }
  if (p == 0) {
    cc = 0;
    for (int i = 0; i < Edge[x].size(); i++) {
      if (Type[x][i] == 2) cc++;
    }
    if (cc > 1) {
      Cut[x] = 1;
    }
  } else {
    for (int i = 0; i < Edge[x].size(); i++) {
      if (Type[x][i] == 2) {
        if (L[Edge[x][i]] >= Dfn[x]) {
          Cut[x] = 1;
        }
      }
    }
  }
  return L[x];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    cin >> a >> b;
    Edge[a].push_back(b);
    Type[a].push_back(0);
    Edge[b].push_back(a);
    Type[b].push_back(0);
  }

  for (int i = 1; i < V + 1; i++) {
    dfn = 0;
    if (Dfn[i] == 0) dfs(i, 0);
  }
  for (int i = 1; i < V + 1; i++) {
    if (Dfn[i] == 1) dfs2(i, 0);
  }
  for (int i = 1; i < V + 1; i++) {
    if (Cut[i] == 1) {
      cnt++;
    }
  }
  cout << cnt << "\n";
  for (int i = 1; i < V + 1; i++) {
    if (Cut[i] == 1) {
      cout << i << " ";
    }
  }
  cout << "\n";

  return 0;
}