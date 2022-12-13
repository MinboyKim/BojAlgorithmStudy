#include <algorithm>
#include <iostream>

using namespace std;

int ans;

int Arr[3];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 3; i++) {
    cin >> Arr[i];
  }

  if (Arr[0] == Arr[1] && Arr[1] == Arr[2])
    cout << 10000 + Arr[0] * 1000 << "\n";
  else if (Arr[0] == Arr[1]) {
    cout << 1000 + Arr[0] * 100 << "\n";
  } else if (Arr[1] == Arr[2]) {
    cout << 1000 + Arr[1] * 100 << "\n";
  } else if (Arr[2] == Arr[0]) {
    cout << 1000 + Arr[2] * 100 << "\n";
  } else {
    cout << *max_element(Arr, Arr + 3) * 100 << "\n";
  }

  return 0;
}