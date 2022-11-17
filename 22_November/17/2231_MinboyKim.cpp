#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int N;
  cin >> N;

  for (int i = 1; i < N; i++) {
    string temp = to_string(i);
    int plus = i;
    for (int j = 0; j < temp.length(); j++) {
      plus += (int)(temp[j]) - 48;
    }
    if (plus == N) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << 0 << "\n";
  return 0;
}