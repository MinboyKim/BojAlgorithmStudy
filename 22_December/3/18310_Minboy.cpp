#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int N;
int Arr[202020];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
  }
  sort(Arr, Arr + N);

  cout << Arr[(N - 1) / 2] << "\n";

  return 0;
}