#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

int N, Q;
bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<0>(a) < get<0>(b);
}
tuple<int, int, int> bar[101'010];
int group[101'010];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    bar[i] = {a, b, i};
  }

  sort(bar, bar + N, compare);

  int num = 0;
  int base = get<1>(bar[0]);
  group[0] = num;

  for (int i = 1; i < N; i++) {
    if (get<0>(bar[i]) <= base) {
      if (get<1>(bar[i]) > base) base = get<1>(bar[i]);
    } else {
      num++;
      base = get<1>(bar[i]);
    }
    group[get<2>(bar[i])] = num;
  }
  while (Q--) {
    cin >> a >> b;
    a--;
    b--;
    if (group[a] == group[b])
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  }

  return 0;
}
