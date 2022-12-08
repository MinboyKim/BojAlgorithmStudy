#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int Arr[10101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int first = 0, second = 0;

  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        int a;
        cin >> a;
        Arr[a]++;
      }
    }

    for (int i = 0; i < 10101; i++) {
      if (Arr[i] > first) {
        second = first;
        first = Arr[i];
      } else if (Arr[i] > second)
        second = Arr[i];
    }

    for (int i = 0; i < 10101; i++) {
      if (Arr[i] == second) cout << i << " ";
      Arr[i] = 0;
    }
    cout << "\n";
    first = 0;
    second = 0;
  }

  return 0;
}