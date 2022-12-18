#include <algorithm>
#include <cstdio>
#include <tuple>

using namespace std;

int N, Q;
bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<0>(a) < get<0>(b);
}
tuple<int, int, int> bar[100'001];
int group[100'001];

int main(void) {
  scanf("%d%d", &N, &Q);
  for (int i = 0; i < N; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    bar[i] = {a, b, i};
  }

  sort(bar, bar + N, compare);

  int sid = 0, e = get<1>(bar[0]);
  group[0] = sid;

  for (int i = 1; i < N; i++) {
    if (get<0>(bar[i]) <= e) {
      if (get<1>(bar[i]) > e) e = get<1>(bar[i]);
    } else {
      sid++;
      e = get<1>(bar[i]);
    }
    group[get<2>(bar[i])] = sid;
  }
  while (Q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    if (group[u] == group[v])
      puts("1");
    else
      puts("0");
  }

  return 0;
}
