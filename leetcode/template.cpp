#include "leetcode/header.h"

// code here

int main() {
    vector<string> lines;
    string s;
    while (getline(cin, s)) {
        reverse(s.begin(), s.end());
        lines.push_back(s);
    }

    int ind = 0;
    while (ind < lines.size()) {
        // args here
    }
}
