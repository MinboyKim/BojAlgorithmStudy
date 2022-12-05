#include <iostream>

using namespace std;

int N, M;

int Arr[20'000'020];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a;
  cin >> N;
  while (N--) {
    cin >> a;
    Arr[a + 10'000'000]++;
  }

  cin >> M;
  while (M--) {
    cin >> a;
    cout << Arr[a + 10'000'000] << " ";
  }
  cout << "\n";

  return 0;
}