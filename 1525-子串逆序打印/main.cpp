// 1216KB	847B	40MS
// The front and end might contain space
#include <stdio.h>
#include <string.h>

const int MAX_N = 100000 + 1000;

char in[MAX_N];
char tmp[MAX_N]; int tmpp;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (!n) break;

		while(getchar()!='\n');

		fgets(in, MAX_N, stdin);
		// n = strlen(in);
		in[n] = ' '; n++; in[n] = 0;

		// PE might occur without this line
		if (' ' == in[0]) putchar(' ');

		bool first = true;
		for (int i = 0; i < n; i++) {
			char cc = in[i];
			if (' ' == cc) {
				if (tmpp) {
					if (first) first = false;
					else putchar(' ');
					for (int i = tmpp - 1; i >= 0; i--) putchar(tmp[i]);
					tmpp = 0;
				}
				continue;
			} else tmp[tmpp++] = cc;
		}
		// PE might occur without this line
		if (' ' == in[n - 2]) putchar(' ');

		putchar('\n');
	}
}