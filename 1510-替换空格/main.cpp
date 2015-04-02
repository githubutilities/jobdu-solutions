// 1772KB   854B    30MS
#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    
    while(getline(cin, line)) {
        /*
        for (size_t i = 0; i < line.length(); i++) {
            char cc = line[i];
            if (' ' == cc) {
                    // string.erase(starting point, offset);
                    // count from zero
                line.erase(i, 1);
                    // string.insert(inserting position, string);
                    // count from zero
                line.insert(i, "%20");
            }
        }
        */
        for (size_t i = 0; i < line.length(); i++) {
            char cc = line[i];
            if (' ' == cc) cout << "%20";
            else cout << cc;
        }
        cout << endl;
    }
}