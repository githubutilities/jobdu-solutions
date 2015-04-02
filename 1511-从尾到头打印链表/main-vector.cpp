// 2292KB	305B	160MS
// cin may cause TLE
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	vector<int> vec;
	int tmp;
	while (cin >> tmp) {
		if (-1 == tmp) break;
		vec.push_back(tmp);
	}
	for (int i = vec.size() - 1; i >= 0; i--) printf("%d\n", vec[i]);
}