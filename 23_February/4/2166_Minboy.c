#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int N;
double X_Sum, Y_Sum;
double X_Arr[10101], Y_Arr[10101];

int main(void) {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) scanf("%lf %lf", &X_Arr[i], &Y_Arr[i]);

  for (int i = 0; i < N - 1; i++) {
    X_Sum += X_Arr[i] * Y_Arr[i + 1];
    Y_Sum += Y_Arr[i] * X_Arr[i + 1];
  }
  X_Sum += X_Arr[N - 1] * Y_Arr[0];
  Y_Sum += Y_Arr[N - 1] * X_Arr[0];

  printf("%.1lf\n", (abs(X_Sum - Y_Sum) / 2));

  return 0;
}