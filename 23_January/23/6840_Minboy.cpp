#include <algorithm>
#include <iostream>

using namespace std;

int Arr[3];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 3; i++) cin >> Arr[i];
  sort(Arr, Arr + 3);
  cout << Arr[1] << "\n";

  return 0;
}