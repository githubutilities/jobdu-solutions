// 1916KB	329B	150MS
// cin may cause TLE

#include <stack>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    stack<int> stk;
    int tmp;
    while (cin >> tmp) {
        if (-1 == tmp) break;
        stk.push(tmp);
    }
    while (!stk.empty())
        printf("%d\n", stk.top()), stk.pop();
}