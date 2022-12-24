#include <iostream>

using namespace std;

int N, M;
int Arr1[101][101];
int Arr2[101][101];
int Sum[101][101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> Arr1[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> Arr2[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      Sum[i][j] = Arr1[i][j] + Arr2[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << Sum[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}