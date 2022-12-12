#include <iostream>

using namespace std;

int Max;
int iIndex;
int jIndex;
int Arr[9][9];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> Arr[i][j];
      if (Max < Arr[i][j]) {
        Max = Arr[i][j];
        iIndex = i;
        jIndex = j;
      }
    }
  }

  cout << Max << "\n" << iIndex + 1 << " " << jIndex + 1 << "\n";

  return 0;
}