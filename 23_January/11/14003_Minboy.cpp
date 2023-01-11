#include <iostream>
#include <vector>

using namespace std;

int N;
int Arr[1'000'000];
int LIS[1'000'000];
int trace[1'000'000];
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

  cin >> N;
  for (int i = 0; i < N; i++) cin >> Arr[i];

  LIS[0] = Arr[0];
  int size = 1;
  for (int i = 1; i < N; i++) {
    if (LIS[size - 1] < Arr[i]) {
      LIS[size] = Arr[i];
      trace[i] = size;
      size++;
    } else {
      int index = binarySearch(size, Arr[i]);
      LIS[index] = Arr[i];
      trace[i] = index;
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    if (trace[i] == size - 1) {
      ans.push_back(Arr[i]);
      size--;
    }
  }

  cout << ans.size() << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}