#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<pair<int, string>> Vec;

bool cmp(pair<int, string> a, pair<int, string> b) { return a.first < b.first; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  int a;
  string s;

  for (int i = 0; i < N; i++) {
    cin >> a >> s;
    Vec.push_back(make_pair(a, s));
  }

  stable_sort(Vec.begin(), Vec.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << Vec[i].first << " " << Vec[i].second << "\n";
  }

  return 0;
}