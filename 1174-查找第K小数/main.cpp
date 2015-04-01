// 1024KB	951B	10MS
// Quicksort + Unique

#include <stdio.h>

const int MAX_N = int(1e3) + 10;

void quicksort(int arr[], int begin, int end) {
	if (begin == end) return;
	int x = arr[begin];
	int i = begin;
	for (int j = i + 1; j < end; j++) {
		if (arr[j] <= x) {
			i++;
			if (i != j) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	int tmp = arr[i];
	arr[i] = x;
	arr[begin] = tmp;
	quicksort(arr, begin, i); quicksort(arr, i + 1, end);
}

void uniq(int arr[], int &len) {
	int i = 0, j = 1;
	for (; j < len; j++) 
		if (arr[j] == arr[i]) continue;
		else arr[++i] = arr[j];
	len = i + 1;
}
int in[MAX_N];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) 
			scanf("%d", in + i);

		quicksort(in, 0, n);
		uniq(in, n);

		int k; scanf("%d", &k);
		printf("%d\n", in[k - 1]);
	}
}