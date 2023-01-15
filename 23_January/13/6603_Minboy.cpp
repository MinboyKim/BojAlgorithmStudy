#include <iostream>

using namespace std;

int k;
int S[15];
int check[15];

void dfs(int d, int next) {
  if (d == 6) {
    for (int i = 0; i < k; i++) {
      if (check[i]) cout << S[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = next; i < k; i++) {
    check[i] = 1;
    dfs(d + 1, i + 1);
    check[i] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    cin >> k;
    if (!k) break;
    for (int i = 0; i < k; i++) cin >> S[i];
    dfs(0, 0);
    cout << "\n";
  }

  return 0;
}