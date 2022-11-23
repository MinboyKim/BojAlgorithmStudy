#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool Visit[10];

void dfs(int c) {
  if (c == M) {
    for (int i = 0; i < M; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (!Visit[i]) {
      Visit[i] = true;
      arr[c] = i;
      dfs(c + 1);
      Visit[i] = false;
    }
  }
}

int main(void) {
  cin >> N >> M;

  dfs(0);

  return 0;
}