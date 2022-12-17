#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, Q, id;
bool flag;
double k;
pair<int, int> dot[100'010];

int binarySearch(double k) {
  int l = 0;
  int r = N - 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (k == dot[mid].first) {
      flag = true;
      return mid;
    } else if (k < dot[mid].first)
      r = mid;
    else
      l = mid;
  }
  return l;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> dot[i].first >> dot[i].second;
  }

  sort(dot, dot + N);

  cin >> Q;

  while (Q--) {
    flag = false;
    cin >> k;
    id = binarySearch(k);
    if (flag) {
      if (dot[id - 1].second < dot[id].second &&
          dot[id].second < dot[id + 1].second)
        cout << 1 << "\n";
      else if (dot[id - 1].second > dot[id].second &&
               dot[id].second > dot[id + 1].second)
        cout << -1 << "\n";
      else
        cout << 0 << "\n";
    } else {
      if (dot[id].second < dot[id + 1].second)
        cout << 1 << "\n";
      else if (dot[id].second > dot[id + 1].second)
        cout << -1 << "\n";
      else
        cout << 0 << "\n";
    }
  }

  return 0;
}