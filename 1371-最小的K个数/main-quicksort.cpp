// 2196KB	849B	940MS
// based on the idea of quicksort
#include <stdio.h>

const int MAX_N = 200000 + 10;

int kk;
void quicksort(int arr[], int begin, int end) {
	if (begin == end) return;
	int x = arr[begin];
	int i = begin;
	for (int j = i + 1; j < end; j++) {
		if (arr[j] <= x) {
			i++;
			if (i != j) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	int tmp = arr[i];
	arr[i] = x;
	arr[begin] = tmp;

	quicksort(arr, begin, i);
	if (i - begin + 1 < kk) quicksort(arr, i + 1, end);
}
int in[MAX_N];
int main() {
	int n; 
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &kk);
		for (int i = 0; i < n; i++) 
			scanf("%d", in + i);

		quicksort(in, 0, n);

		for (int i = 0; i < kk; i++)
			printf("%d%c", in[i], kk - 1 == i ? '\n': ' ');
	}
}