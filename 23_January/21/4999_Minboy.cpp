#include <iostream>
#include <string>

using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;

  int cnt = 0;
  int cnt1 = 0;

  for (int i = 0; i < str1.length(); i++) {
    if (str1[i] == 'a') {
      cnt++;
    }
  }

  for (int i = 0; i < str2.length(); i++) {
    if (str2[i] == 'a') {
      cnt1++;
    }
  }
  if (cnt >= cnt1 || str1.length() == str2.length()) {
    cout << "go";
  } else {
    cout << "no";
  }
}