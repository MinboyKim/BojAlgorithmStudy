#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
int Parent[55];
vector<int> truth;
vector<int> party[55];

int Find_Parent(int a) {
  if (a == Parent[a]) return a;
  return Parent[a] = Find_Parent(Parent[a]);
}

void Union(int a, int b) {
  a = Find_Parent(a);
  b = Find_Parent(b);
  Parent[b] = a;
}

bool Same_Parent(int a, int b) {
  a = Find_Parent(a);
  b = Find_Parent(b);
  if (a == b) return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  int num, a;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> a;
    truth.push_back(a);
  }

  for (int i = 0; i < M; i++) {
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> a;
      party[i].push_back(a);
    }
  }
  ans = M;

  for (int i = 1; i <= N; i++) Parent[i] = i;
  for (int i = 0; i < M; i++) {
    int one = party[i][0];
    for (int j = 1; j < party[i].size(); j++) {
      int two = party[i][j];
      Union(one, two);
    }
  }

  for (int i = 0; i < M; i++) {
    bool flag = true;
    for (auto &j : party[i]) {
      if (!flag) break;
      for (auto &k : truth) {
        if (Same_Parent(j, k)) {
          flag = false;
          break;
        }
      }
    }
    if (!flag) ans--;
  }

  cout << ans << "\n";

  return 0;
}