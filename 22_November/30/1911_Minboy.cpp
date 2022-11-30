#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, L;

vector<pair<int, int>> Arr;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    Arr.push_back({a, b});
  }
  sort(Arr.begin(), Arr.end());

  int ans = 0;
  int index = 0;
  for (auto& i : Arr) {
    if (i.first > index) index = i.first;
    while (index < i.second) {
      index += L;
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}