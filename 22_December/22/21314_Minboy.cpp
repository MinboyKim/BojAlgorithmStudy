#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string s;

void solve() {
  string maxNum;
  string minNum;
  string temp;
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'M')
      count++;
    else {
      if (count > 0) {
        temp = "1";
        for (int i = 0; i < count - 1; i++) temp += '0';
        temp += '5';
        minNum += temp;
        temp = "5";
        for (int i = 0; i < count; i++) temp += '0';
        maxNum += temp;
      } else {
        maxNum += '5';
        minNum += '5';
      }
      count = 0;
    }
  }
  if (count > 0) {
    for (int i = 0; i < count; i++) {
      maxNum += '1';
    }
    temp = "1";
    for (int i = 0; i < count - 1; i++) temp += '0';
    minNum += temp;
  }
  cout << maxNum << "\n" << minNum << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  solve();
  return 0;
}