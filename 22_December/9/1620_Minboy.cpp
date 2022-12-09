#include <iostream>
#include <map>

using namespace std;

int N, M;
map<string, int> dict_name;
map<int, string> dict_num;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int a = 1;
  cin >> N >> M;

  while (N--) {
    cin >> s;
    dict_name.insert({s, a});
    dict_num.insert({a, s});
    a++;
  }

  while (M--) {
    cin >> s;
    if (dict_name.find(s) != dict_name.end())
      cout << dict_name.at(s) << "\n";
    else {
      cout << dict_num.at(stoi(s)) << "\n";
    }
  }

  return 0;
}