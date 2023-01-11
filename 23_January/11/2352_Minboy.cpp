#include <iostream>

using namespace std;

int n;
int wire[40404];
int LIS[40404];

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

  cin >> n;
  for (int i = 0; i < n; i++) cin >> wire[i];

  LIS[0] = wire[0];
  int size = 1;
  for (int i = 1; i < n; i++) {
    if (LIS[size - 1] < wire[i]) {
      LIS[size] = wire[i];
      size++;
    } else {
      int index = binarySearch(size, wire[i]);
      LIS[index] = wire[i];
    }
  }

  cout << size << "\n";

  return 0;
}