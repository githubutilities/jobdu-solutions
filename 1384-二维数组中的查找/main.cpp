// 5004KB	434B	680MS
// bruteforce -- scan through
#include <stdio.h>

const int MAX_N = int(1e3) + 10;

int mp[MAX_N][MAX_N];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int qu; scanf("%d", &qu);
		bool yes = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int tmp; scanf("%d", &tmp);
				if (tmp == qu) yes = true;
			}
		if (yes) puts("Yes");
		else puts("No");
	}
}