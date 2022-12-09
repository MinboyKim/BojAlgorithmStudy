#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Arr;
vector<int> sortedUniqueArr;

int binarySearch(int l, int r, int target) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (sortedUniqueArr[mid] == target)
      return mid;
    else if (sortedUniqueArr[mid] > target)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    Arr.push_back(temp);
  }
  sortedUniqueArr = Arr;
  sort(sortedUniqueArr.begin(), sortedUniqueArr.end());
  sortedUniqueArr.erase(unique(sortedUniqueArr.begin(), sortedUniqueArr.end()),
                        sortedUniqueArr.end());
  for (int i = 0; i < N; i++) {
    cout << binarySearch(0, sortedUniqueArr.size(), Arr[i]) << " ";
  }
  cout << "\n";
  return 0;
}