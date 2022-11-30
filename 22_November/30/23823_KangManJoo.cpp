#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int colmax = 0,rowmax=0;
	int colmaxnum = 0,rowmaxnum=0;
	int n, q,t,a;
	cin >> n >> q;
	int col[30001]={0};
	int row[30001]={0};
	while (q--) {
		cin >> t >> a;
		a = a - 1;
		if (t == 1) {
			col[a]++;
			if (col[a] > colmax) {
				colmax = col[a];
				colmaxnum = 1;
			}
			else if (col[a] == colmax) {
				colmaxnum++;
			}

		}
		else{
			row[a]++;
			if (row[a] > rowmax) {
				rowmax = row[a];
				rowmaxnum = 1;
			}
			else if (row[a] == rowmax) {
				rowmaxnum++;
			}
		}
		if (colmaxnum == 0) {
			cout<<rowmaxnum* n<<'\n';
		}
		else if (rowmaxnum == 0) {
			cout << colmaxnum* n << '\n';
		}
		else cout<< colmaxnum*rowmaxnum<<'\n';
	}
	//cout << max << '\n' << maxnum;
	return 0;
}