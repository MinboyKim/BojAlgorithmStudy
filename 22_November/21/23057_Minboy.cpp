#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, sum;
vector<int> card;
set<int> s;

int main(void) {
  int a;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    card.push_back(a);
    s.insert(a);
    sum += a;
  }

  for (int i = 1; i <= card.size(); i++) {
    vector<bool> v(card.size() - i, false);
    v.insert(v.end(), i, true);
    do {
      int temp = 0;
      for (int k = 0; k < card.size(); k++) {
        if (v[k]) temp += card[k];
      }
      s.insert(temp);
    } while (next_permutation(v.begin(), v.end()));
  }

  cout << sum - s.size() << "\n";

  return 0;
}