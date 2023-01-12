#include <iostream>

using namespace std;

int N;
int Arr[1'000'010];
int LIS[1'000'010];

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

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  LIS[0] = Arr[0];
  int size = 1;
  for (int i = 1; i < N; i++) {
    if (Arr[i] > LIS[size - 1]) {
      LIS[size] = Arr[i];
      size++;
    } else {
      int index = binarySearch(size, Arr[i]);
      LIS[index] = Arr[i];
    }
  }

  cout << size << "\n";

  return 0;
}