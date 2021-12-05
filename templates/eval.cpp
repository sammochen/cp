ll eval(const string& s) {
    const ll n = s.size();
    ll dep = 0, start = -1, val = 0;
    VLL nums;
    string signs;

    for (ll i = 0; i < n; i++) {
        if (s[i] == ' ') continue;

        if (s[i] == '(') {
            if (dep++ == 0) {
                start = i;
            }
        } else if (s[i] == ')') {
            if (--dep == 0) {
                string inside = s.substr(start + 1, i - start - 1);
                val = eval(inside);
            }
        } else {
            if (dep != 0) continue;

            if (s[i] >= '0' && s[i] <= '9') {
                val *= 10;
                val += s[i] - '0';
            } else {
                // If the previous sign was * or /, execute first
                if (signs.size() && (signs.back() == '*' || signs.back() == '/')) {
                    if (signs.back() == '*') {
                        nums.back() *= val;
                    } else {
                        nums.back() /= val;  // careful floor
                    }
                    signs.back() = s[i];
                    val = 0;
                } else {
                    nums.push_back(val);
                    signs.push_back(s[i]);
                    val = 0;
                }
            }
        }
    }

    nums.push_back(val);

    ll ans = nums[0];
    for (ll i = 0; i < signs.size(); i++) {
        if (signs[i] == '+') {
            ans += nums[i + 1];
        } else if (signs[i] == '-') {
            ans -= nums[i + 1];
        } else {
            assert(false);
        }
    }
    return ans;
}
