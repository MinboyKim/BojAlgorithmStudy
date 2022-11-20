#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

void solve() {
  while (true) {
    int a = q.front();
    q.pop();
    if (q.empty()) {
      cout << a << "\n";
      return;
    }
    int b = q.front();
    q.pop();
    q.push(b);
  }
}

int main(void) {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    q.push(i);
  }
  solve();
  return 0;
}