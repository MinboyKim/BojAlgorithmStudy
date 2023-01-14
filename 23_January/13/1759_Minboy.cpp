#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int L, C;
char Arr[20];
int check[20];
vector<string> ans;

void dfs(int d, int next) {
  if (d == L) {
    bool constFlag = false;
    int vowelCnt = 0;
    string s = "";
    for (int i = 0; i < C; i++) {
      if (check[i]) {
        if (Arr[i] == 'a' || Arr[i] == 'e' || Arr[i] == 'i' || Arr[i] == 'o' ||
            Arr[i] == 'u')
          constFlag = true;
        else
          vowelCnt++;
        s += Arr[i];
      }
    }
    if (constFlag && vowelCnt > 1) ans.push_back(s);
  }
  for (int i = next; i < C; i++) {
    check[i] = 1;
    dfs(d + 1, i + 1);
    check[i] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> L >> C;
  for (int i = 0; i < C; i++) cin >> Arr[i];
  sort(Arr, Arr + C);

  dfs(0, 0);

  for (auto &i : ans) cout << i << "\n";

  return 0;
}
