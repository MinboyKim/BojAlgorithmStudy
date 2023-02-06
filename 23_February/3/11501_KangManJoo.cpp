#include <bits/stdc++.h>

using namespace std;

int t, n;
int arr[1001001];
int maxCost;
int maxLoc;
long long sum;

void solve() {
    sum = 0;
    maxCost = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] >= maxCost) {
            maxCost = arr[i];
            maxLoc = i;
        }
    }
    int preLoc = 0;
    while (maxCost) {
        for (int i = preLoc; i <= maxLoc; i++) {
            sum += maxCost - arr[i];
        }
        maxCost = 0;
        preLoc = maxLoc + 1;
        for (int i = preLoc; i < n; i++) {
            if (arr[i] >= maxCost) {
                maxCost = arr[i];
                maxLoc = i;
            }
        }
    }
    cout << sum<< endl;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

