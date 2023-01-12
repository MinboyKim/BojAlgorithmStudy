#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int card[500'500];

bool binary_search(int target) {
  int l = 0;
  int r = N - 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (card[mid] > target)
      r = mid;
    else
      l = mid;
  }
  if (card[l] == target || card[r] == target)
    return true;
  else
    return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int target;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> card[i];

  sort(card, card + N);

  cin >> M;
  while (M--) {
    cin >> target;
    if (binary_search(target))
      cout << 1 << " ";
    else
      cout << 0 << " ";
  }
  cout << "\n";

  return 0;
}