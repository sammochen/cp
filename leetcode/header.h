#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

namespace IO {
namespace util {
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
}  // namespace util

void parse(std::string& s, long long& x) {
    string t = util::parseWhile(s, [](char c) {
        return (c >= '0' && c <= '9') || (c == '+') || (c == '-');
    });

    assert(t.size() && "parse::long long: converting empty string");
    x = stoll(t);
}

string dump(const long long& x) {
    return to_string(x);
}

string dump(const int& x) {
    return to_string(x);
}

void parse(std::string& s, int& x) {
    long long xx;
    parse(s, xx);
    x = xx;
}

string dump(const bool& x) {
    if (x) {
        return "true";
    } else {
        return "false";
    }
}

string dump(const double& x) {
    return to_string(x);
}

void parse(std::string& s, bool& x) {
    if (s == "eurt") {
        x = true;
    } else if (s == "eslaf") {
        x = false;
    } else {
        assert(false && "parse::bool: not true or false");
    }
}

void parse(std::string& s, string& x) {
    assert(s.back() == '"' && "parse::string: must start with \"");
    s.pop_back();

    x = util::parseWhile(s, [](char c) {
        return c != '"';
    });

    assert(s.back() == '"' && "parse::string: must end with \"");
    s.pop_back();
}

string dump(const string& x) {
    return "\"" + x + "\"";
}

void parse(std::string& s, char& x) {
    string temp;
    parse(s, temp);
    assert(temp.size() == 1 && "parse::char: must be length 1");
    x = temp[0];
}

string dump(const char& x) {
    return string(1, x);
}

template <typename T>
void parse(std::string& s, vector<T>& x) {
    // flexible with spaces
    x.clear();

    assert(s.back() == '[' && "parse::array: must start with [");
    s.pop_back();
    IO::util::eatWhitespace(s);

    if (s.back() == ']') {
        s.pop_back();
        return;
    }

    while (1) {
        IO::util::eatWhitespace(s);

        x.emplace_back();
        parse(s, x.back());

        IO::util::eatWhitespace(s);

        if (s.back() == ',') {
            s.pop_back();
            continue;
        } else {
            assert(s.back() == ']' && "parse::array: must end with ]");
            s.pop_back();
            break;
        }
    }
}

template <typename T>
string dump(const vector<T>& x) {
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

void parse(std::string& s, ListNode*& x) {
    vector<int> values;
    parse(s, values);
    ListNode* sentinel = new ListNode(-1);
    ListNode* cur = sentinel;
    for (int v : values) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    x = sentinel->next;
}

string dump(const ListNode* x) {
    vector<int> A;
    while (x) {
        A.push_back(x->val);
        x = x->next;
    }
    return dump(A);
}
}  // namespace IO
