#include <algorithm>
#include <iostream>

using namespace std;

int box[2222];
int N, K;

void solve() {
  int eatCnt = 0, date = 0;
  for (int i = K; i < N; i++) {
    if (box[i] == box[i - K]) continue;
    while (box[i - K] != box[i]) {
      eatCnt++;
      box[i]--;
    }
    i--;
    date++;
    sort(box, box + N);
  }
  cout << eatCnt << " " << date << "\n";
}

int main(void) {
  int a;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> a;
    box[i] = a;
  }

  solve();

  return 0;
}