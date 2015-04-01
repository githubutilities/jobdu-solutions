// 1800KB	1243B	920MS
// use heap of k size

#include <stdio.h>
#include <algorithm>

using namespace std;

#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)

const int MAX_N = 200000 + 10;

int arr[MAX_N];

void swap (int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void max_heap_adjust(int arr[], int size, int i) {
	int ll = LEFT(i);
	int rr = RIGHT(i);
	int max = i;
	if (i <= (size * 2)) {
		if (ll <= size && arr[ll] > arr[max])
			max = ll;
		if (rr <= size && arr[rr] > arr[max])
			max = rr;
		if (max != i) {
			swap(arr[max], arr[i]);
			max_heap_adjust(arr, size, max);
		}
	}
}
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		for (int i = 1; i <= k; i++)
			scanf("%d", arr + i);

		// build heap
		for (int i = k / 2; i >= 1; i--) 
			max_heap_adjust(arr, k, i);

		// insert node into heap
		for (int i = k + 1; i <= n; i++) {
			int tmp; scanf("%d", &tmp);
			if (tmp < arr[1]) {
				arr[1] = tmp;
				max_heap_adjust(arr, k, 1);
			}
		}

		sort(arr + 1, arr + k + 1);
		for (int i = 1; i <= k; i++) 
			printf("%d%c", arr[i], k == i ? '\n': ' ');

	}
}