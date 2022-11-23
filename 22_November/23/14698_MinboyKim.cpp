#include <tgmath.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print_ans(vector<long long> ans) {
  long long result = 1;
  for (auto i : ans) {
    result = (result * i) % 1000000007;
  }
  cout << result % 1000000007 << "\n";
  return;
}

void solve(
    priority_queue<long long, vector<long long>, greater<long long> > energy) {
  if (energy.size() == 1) {
    energy.pop();
    cout << "1"
         << "\n";
    return;
  }
  vector<long long> ans;
  while (!energy.empty()) {
    long long a = energy.top();
    energy.pop();
    long long b = energy.top();
    energy.pop();
    ans.push_back((a * b) % 1000000007);
    if (energy.empty()) {
      print_ans(ans);
      return;
    }
    energy.push(a * b);
  }
  return;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    priority_queue<long long, vector<long long>, greater<long long> > energy;
    cin >> N;
    while (N--) {
      long long a;
      cin >> a;
      energy.push(a);
    }
    solve(energy);
  }

  return 0;
}