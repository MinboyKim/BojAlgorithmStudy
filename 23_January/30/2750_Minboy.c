#include <stdio.h>
#include <stdlib.h>

int N;
int Arr[1010];

int static compare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  else if (*(int*)a < *(int*)b)
    return -1;
  else
    return 0;
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &Arr[i]);

  qsort(Arr, N, sizeof(int), compare);

  for (int i = 0; i < N; i++) printf("%d\n", Arr[i]);

  return 0;
}