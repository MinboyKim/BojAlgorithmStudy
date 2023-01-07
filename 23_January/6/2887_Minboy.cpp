#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N, ans;
vector<pair<int, int>> planet[101'010];
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int Visit[101010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y, z;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> z;
    X.push_back({x, i});
    Y.push_back({y, i});
    Z.push_back({z, i});
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  sort(Z.begin(), Z.end());

  for (int i = 0; i < N - 1; i++) {
    planet[X[i].second].push_back(
        {X[i + 1].first - X[i].first, X[i + 1].second});
    planet[X[i + 1].second].push_back(
        {X[i + 1].first - X[i].first, X[i].second});
    planet[Y[i].second].push_back(
        {Y[i + 1].first - Y[i].first, Y[i + 1].second});
    planet[Y[i + 1].second].push_back(
        {Y[i + 1].first - Y[i].first, Y[i].second});
    planet[Z[i].second].push_back(
        {Z[i + 1].first - Z[i].first, Z[i + 1].second});
    planet[Z[i + 1].second].push_back(
        {Z[i + 1].first - Z[i].first, Z[i].second});
  }

  Visit[0] = 1;
  for (auto &i : planet[0]) pq.push(i);

  while (!pq.empty()) {
    pair<int, int> temp = pq.top();
    pq.pop();
    if (Visit[temp.second]) continue;
    Visit[temp.second] = 1;
    ans += temp.first;
    for (auto &i : planet[temp.second]) pq.push(i);
  }

  cout << ans << "\n";

  return 0;
}