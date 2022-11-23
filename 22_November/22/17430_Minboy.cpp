// fail time over

#include <algorithm>
#include <iostream>

using namespace std;

int T, N;
pair<int, int> Arr[200000];

bool cmp(pair<int, int> a, pair<int, int> b) {
  pair<int, int> new_a = make_pair(a.first, b.second);
  pair<int, int> new_b = make_pair(b.first, a.second);

  if ((find(begin(Arr), end(Arr), new_a) != end(Arr)) &&
      (find(begin(Arr), end(Arr), new_b) != end(Arr)))
    return true;
  else
    return false;
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (cmp(Arr[i], Arr[j]))
        continue;
      else {
        cout << "NOT BALANCED\n";
        return;
      }
    }
  }
  cout << "BALANCED\n";
  for (int i = 0; i < 200000; i++) {
    Arr[i] = make_pair(0, 0);
  }
}

int main(void) {
  int a, b;
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> a >> b;
      Arr[i] = make_pair(a, b);
    }
    solve();
  }
  return 0;
}