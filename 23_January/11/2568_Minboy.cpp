#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> wire;
int LIS[500'005];
int trace[500'005];
vector<int> ans;

int binarySearch(int size, int target) {
  int l = 0;
  int r = size - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (LIS[mid] == target)
      return mid;
    else if (LIS[mid] > target)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    wire.push_back({a, b});
  }

  sort(wire.begin(), wire.end());

  LIS[0] = wire[0].second;
  int size = 1;
  for (int i = 1; i < N; i++) {
    if (LIS[size - 1] < wire[i].second) {
      LIS[size] = wire[i].second;
      trace[i] = size;
      size++;
    } else {
      int index = binarySearch(size, wire[i].second);
      LIS[index] = wire[i].second;
      trace[i] = index;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    if (trace[i] == size - 1) {
      wire.erase(wire.begin() + i);
      size--;
    }
  }

  cout << wire.size() << "\n";
  for (auto &i : wire) cout << i.first << "\n";

  return 0;
}