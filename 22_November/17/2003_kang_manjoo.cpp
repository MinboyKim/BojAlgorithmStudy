#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int main(void) {
	int N,M=0,x;
	int count,c2 = 0;
	cin >> N;
	cin >> M;
	cin.ignore();
	vector<int> A;

	for (int i = 0; i < N; i++) {
		cin >> x;
		A.push_back(x);
	}

	for (int j = 0; j < N; j++) {
		count = 0;
		for (int K = j; K < N; K++) {
			count += A[K];
			if (count == M) {
				c2++;
			}
		}
	}
	cout<<c2;
}