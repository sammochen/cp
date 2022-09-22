#include <bits/stdc++.h>
using namespace std;

namespace IO {
template <typename F>
string parseWhile(string& s, F&& isGood) {
    string ret;
    while (s.size() && isGood(s.back())) {
        ret.push_back(s.back());
        s.pop_back();
    }
    return ret;
}

void eatWhitespace(string& s) {
    parseWhile(s, [](char c) {
        return c == ' ' || c == '\n';
    });
}

void parse(std::string& s, int& x) {
    string t = parseWhile(s, [](char c) {
        return c >= '0' && c <= '9';
    });
    assert(t.size());
    x = stoi(t);
}

void parse(std::string& s, string& x) {
    assert(s.back() == '"');
    s.pop_back();

    x = parseWhile(s, [](char c) {
        return c != '"';
    });

    assert(s.back() == '"');
    s.pop_back();
}

void parse(std::string& s, char& x) {
    string temp;
    parse(s, temp);
    assert(temp.size() == 1);
    x = temp[0];
}

template <typename T>
void parse(std::string& s, vector<T>& x) {
    // flexible with spaces
    x.clear();

    assert(s.back() == '[');
    s.pop_back();

    while (1) {
        eatWhitespace(s);

        x.emplace_back();
        parse(s, x.back());

        eatWhitespace(s);

        if (s.back() == ',') {
            s.pop_back();
            continue;
        } else {
            assert(s.back() == ']');
            s.pop_back();
            break;
        }
    }
}

string dump(int& x) {
    return to_string(x);
}

string dump(string& x) {
    return "\"" + x + "\"";
}

string dump(char& x) {
    return string(1, x);
}

template <typename T>
string dump(vector<T>& x) {
    string s;
    s += "[";
    int first = 1;
    for (auto xx : x) {
        if (!first) s += ",";
        first = 0;
        s += dump(xx);
    }
    s += "]";
    return s;
}

}  // namespace IO

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
