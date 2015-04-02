// 1528KB   2242B   10MS
// recursive

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sub(vector<int> vec, int start, int end) {
    vector<int> ret;
    for (int i = start; i <= end; i++) ret.push_back(vec[i]);
    return ret;
}

bool check(vector<int> pre, vector<int> mid) {
    if (pre.size() != mid.size()) return false;
    sort(pre.begin(), pre.end());
    sort(mid.begin(), mid.end());
    for (int i = 0; i < pre.size(); i++) if(pre[i] != mid[i]) return false;
    return true;
}

vector<int> to_post(vector<int> pre, vector<int> mid) {
//    for (int i = 0; i < pre.size(); i++)
//        printf("%d%c", pre[i], i == pre.size() - 1? '\n':' ');
    if (!check(pre, mid)) {
        vector<int> aa; aa.clear();
        return aa;
    }
    
    int root = pre[0];
    int pos = int(mid.size()) - 1;
    while (pos >= 0) {
        if(mid[pos] == root) break;
        pos--;
    }
    
    if (0 == pos && mid[pos] != root) {
        vector<int> aa; aa.clear();
        return aa;
    }
    
    vector<int> bb, ret;
    if (0 <= pos - 1)
        ret = to_post(sub(pre, 1, pos), sub(mid, 0, pos - 1));
    if (pos + 1 <= int(pre.size()) - 1)
        bb = to_post(sub(pre, pos + 1, int(pre.size()) - 1), sub(mid, pos + 1, int(pre.size()) - 1));
    for (int i = 0; i < bb.size(); i++)
        ret.push_back(bb[i]);
    bb.clear();
    ret.push_back(root);
    return ret;
}

vector<int> pre;
vector<int> mid;

int main() {
    int n;
    while (cin >> n) {
        pre.clear();
        mid.clear();
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            pre.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            mid.push_back(tmp);
        }
        vector<int> ans = to_post(pre, mid);
        if (ans.size() != n) { puts("No"); continue; }
        else {
            // PE might occur here
            for (int i = 0; i < ans.size(); i++)
                printf("%d ", ans[i]);puts("");
        }
    }
}