// 1800KB	730B	230MS
// Union Find
#include <stdio.h>

const int MAX_N = 100000 + 10;

int fa[MAX_N];
int vis[MAX_N];

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void uni(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) fa[x] = y;
	return;
}

int main() {
	int n, m;

	while (scanf("%d", &n), n) {
		scanf("%d", &m);

		for (int i = 1; i <= n; i++) 
			fa[i] = i, vis[i] = false;

		while (m--) {
			int a, b; scanf("%d%d", &a, &b);
			uni(a, b);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = find(i);
			if (!vis[x]) vis[x] = true, ans++;
		}
		printf("%d\n", ans);
	}
}