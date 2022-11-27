#include <iostream>

using namespace std;
int N;
int minsum=100000;
void calc() {
	int sum;
	int i = 0;
	int remain;
	while (true) {
		sum = 0;
		if (i == 0) {
			sum += N / 5;
			remain = (N % 5);
			sum += remain / 2;
			remain = remain % 2;
			sum += remain / 1;
			minsum=(minsum > sum ? sum : minsum);
		}
		else {
			if (N % (i * 7) == N) break;
			sum += i;
			remain = N -(i * 7);
			sum += remain / 5;
			remain = (remain % 5);
			sum += remain / 2;
			remain = remain % 2;
			sum += remain / 1;
			minsum = (minsum > sum ? sum : minsum);
		}
		i++;
	}
	

}

int main() {
	cin >> N;
	
	calc();
	
	printf("%d", minsum);
	return 0;
}