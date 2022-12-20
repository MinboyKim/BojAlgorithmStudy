#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int N, val;
string s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  while (N--) {
    cin >> s;
    if (s == "push") {
      cin >> val;
      q.push(val);
    } else if (s == "pop") {
      if (q.empty())
        cout << -1 << "\n";
      else {
        val = q.front();
        cout << val << "\n";
        q.pop();
      }
    } else if (s == "size")
      cout << q.size() << "\n";
    else if (s == "empty") {
      if (q.empty())
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
    } else if (s == "front") {
      if (q.empty())
        cout << -1 << "\n";
      else {
        val = q.front();
        cout << val << "\n";
      }
    } else {
      if (q.empty())
        cout << -1 << "\n";
      else {
        val = q.back();
        cout << val << "\n";
      }
    }
  }

  return 0;
}