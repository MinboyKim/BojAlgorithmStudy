#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> home;
vector<pair<int, int>> kfc;
int Select[15];
int dist = 999'999'999, kfcCnt;

int check() {
  int ret = 0;
  for (auto &i : home) {
    int temp = 999'999'999;
    for (int j = 0; j < kfc.size(); j++) {
      if (Select[j]) continue;
      temp = min(temp,
                 abs(i.first - kfc[j].first) + abs(i.second - kfc[j].second));
    }
    ret += temp;
  }
  return ret;
}

void dfs(int cnt, int pos) {
  if (cnt == kfcCnt - M) {
    int temp = check();
    if (temp < dist) {
      dist = temp;
    }
    return;
  }
  for (int i = pos; i < kfc.size(); i++) {
    Select[i] = 1;
    dfs(cnt + 1, i + 1);
    Select[i] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a;
      if (a == 1)
        home.push_back({i, j});
      else if (a == 2) {
        kfc.push_back({i, j});
        kfcCnt++;
      }
    }
  }

  dfs(0, 0);

  cout << dist << "\n";

  return 0;
}