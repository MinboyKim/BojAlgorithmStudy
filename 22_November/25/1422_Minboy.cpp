#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int K, N;
int Arr[55];
int Arr2[55];

bool cmp(int a, int b) {
  string as = to_string(a);
  string bs = to_string(b);
  if (as.length() == bs.length())
    return a > b;
  else {
    return as.length() > bs.length();
  }
}
bool cmp2(int a, int b) {
  string as = to_string(a);
  string bs = to_string(b);
  return as + bs > bs + as;
}

int main(void) {
  string ans;
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> K >> N;

  for (int i = 0; i < K; i++) {
    cin >> Arr[i];
  }

  sort(Arr, Arr + K, cmp);

  for (int i = 0; i < K; i++) {
    Arr2[i] = Arr[i];
  }
  for (int i = K; i < N; i++) {
    Arr2[i] = Arr[0];
  }

  sort(Arr2, Arr2 + N, cmp2);

  for (int i = 0; i < N; i++) {
    ans += to_string(Arr2[i]);
  }
  cout << ans << "\n";

  return 0;
}