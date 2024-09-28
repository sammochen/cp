#include "leetcode/header.h"

// code here

int main() {
    vector<string> lines;
    {
        string s;
        while (getline(cin, s)) {
            bool only_whitespace = true;
            for (auto c : s) {
                if (!isspace(c)) {
                    only_whitespace = false;
                    break;
                }
            }
            if (only_whitespace) {
                continue;
            }

            reverse(s.begin(), s.end());
            lines.push_back(s);
        }
    }

    int ind = 0;
    while (ind < lines.size()) {
        // args here
    }
}
