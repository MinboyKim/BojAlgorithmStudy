#include <iostream>
#include <string>

using namespace std;

int N, id;
int Count[2];
string s;

int main(void) {
  cin >> N >> s;
  while (id < s.length()) {
    if (s[id] == 's') {
      Count[0]++;
      id += 8;
    } else {
      Count[1]++;
      id += 7;
    }
  }
  if (Count[0] < Count[1])
    cout << "bigdata?\n";
  else if (Count[1] < Count[0])
    cout << "security!\n";
  else
    cout << "bigdata? security!\n";

  return 0;
}