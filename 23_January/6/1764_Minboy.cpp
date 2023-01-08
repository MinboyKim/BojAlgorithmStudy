#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, M;
map<string, int> mp;
vector<string> dbj;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N + M; i++) {
    string s;
    cin >> s;
    mp[s]++;
    if (mp[s] > 1) dbj.push_back(s);
  }

  sort(dbj.begin(), dbj.end());
  cout << dbj.size() << "\n";
  for (auto &i : dbj) cout << i << "\n";

  return 0;
}