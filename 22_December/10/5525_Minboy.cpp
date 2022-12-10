#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, ans;
string S;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> S;

  for (int i = 0; i < M; i++) {
    int k = 0;
    if (S[i] == 'O')
      continue;
    else {
      while (S[i + 1] == 'O' && S[i + 2] == 'I') {
        k++;
        if (k == N) {
          ans++;
          k--;
        }
        i += 2;
      }
    }
    k = 0;
  }

  cout << ans << "\n";

  return 0;
}
