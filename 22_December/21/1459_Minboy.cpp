#include <cmath>
#include <iostream>

using namespace std;

long long X, Y, W, S;
long long ans;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> X >> Y >> W >> S;

  ans = (X + Y) * W;

  if ((X + Y) % 2 == 0)
    ans = min(ans, max(X, Y) * S);
  else
    ans = min(ans, (max(X, Y) - 1) * S + W);

  ans = min(ans, (min(X, Y) * S) + (abs(X - Y) * W));

  cout << ans << "\n";

  return 0;
}