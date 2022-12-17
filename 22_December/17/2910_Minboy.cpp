#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a;
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> a;
    auto it = find_if(v.begin(), v.end(), [&a](const pair<int, int>& elem) {
      return elem.first == a;
    });
    if (it == v.end()) {
      v.push_back({a, 1});
    } else
      v[it - v.begin()].second++;
  }

  stable_sort(v.begin(), v.end(), compare);

  for (auto i : v) {
    for (int j = 0; j < i.second; j++) {
      cout << i.first << " ";
    }
  }
  cout << "\n";

  return 0;
}
