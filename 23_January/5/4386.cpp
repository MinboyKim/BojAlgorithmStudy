#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
  bool operator()(pair<int, double> a, pair<int, double> b) {
    return a.second > b.second;
  }
};

int n;
double ans;
vector<pair<double, double>> loc;
vector<pair<int, double>> Edges[111];
int Visit[111];
priority_queue<pair<int, double>, vector<pair<int, double>>, compare> pq;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    loc.push_back({x, y});
  }

  for (int i = 0; i < n; i++) {
    double tempX = loc[i].first;
    double tempY = loc[i].second;
    for (int j = i + 1; j < n; j++) {
      double tempX2 = loc[j].first;
      double tempY2 = loc[j].second;
      double distance = dist(tempX, tempY, tempX2, tempY2);
      Edges[i].push_back({j, distance});
      Edges[j].push_back({i, distance});
    }
  }

  Visit[0] = 1;
  for (auto &i : Edges[0]) pq.push(i);

  while (!pq.empty()) {
    pair<int, double> temp = pq.top();
    pq.pop();
    if (Visit[temp.first]) continue;
    ans += temp.second;
    Visit[temp.first] = 1;
    for (auto &i : Edges[temp.first]) pq.push(i);
  }

  cout << ans << "\n";

  return 0;
}