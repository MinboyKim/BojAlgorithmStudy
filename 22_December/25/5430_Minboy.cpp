#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int T;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  while (T--) {
    deque<int> Arr;
    int n;
    bool rFlag = false;
    bool errFlag = false;
    string cmd, s, stringBuffer, ans;
    cin >> cmd >> n >> s;

    s.erase(s.begin() + s.length() - 1);
    s.erase(s.begin());
    istringstream ss(s);
    while (getline(ss, stringBuffer, ',')) {
      Arr.push_back(stoi(stringBuffer));
    }

    for (int i = 0; i < cmd.length(); i++) {
      if (cmd[i] == 'R') {
        rFlag = !rFlag;
        continue;
      }
      if (Arr.empty()) {
        errFlag = true;
        break;
      } else {
        if (rFlag)
          Arr.pop_back();
        else
          Arr.pop_front();
      }
    }
    if (errFlag) {
      cout << "error\n";
      continue;
    }
    if (Arr.empty()) {
      cout << "[]\n";
      continue;
    }
    ans += '[';
    if (rFlag)
      for (auto i = Arr.rbegin(); i != Arr.rend(); i++)
        ans += to_string(*i) + ',';
    else
      for (auto i = Arr.begin(); i != Arr.end(); i++)
        ans += to_string(*i) + ',';
    ans[ans.length() - 1] = ']';
    cout << ans << "\n";
  }
  return 0;
}
