VLL get_radii(const string& t) {
    ll m = lg(t);
    VLL radii(m);

    ll center = 0, radius = 0;
    while (center < m) {
        // increase the center as much as possible
        while (center - (radius + 1) >= 0 && center + (radius + 1) < m &&
               t[center - (radius + 1)] == t[center + (radius + 1)]) {
            radius++;
        }
        radii[center] = radius;

        // increment center until we need to brute force
        const ll old_center = center;
        const ll old_radius = radius;
        center++;
        radius = 0;
        // the center can only go as right as the boundary
        while (center < old_center + old_radius) {
            const ll mirrored_center = old_center - (center - old_center);
            const ll max_mirrored_radius = old_center + old_radius - center;

            if (radii[mirrored_center] < max_mirrored_radius) {
                radii[center] = radii[mirrored_center];
                center++;
            } else if (radii[mirrored_center] > max_mirrored_radius) {
                radii[center] = max_mirrored_radius;
                center++;
            } else {
                // radii[mirrored_center] == max_mirrored_radius
                radius = max_mirrored_radius;
                break;  // brute force center, radius
            }
        }
    }
    return radii;
}

/**
 * Returns the longest palindromic substring in O(n) time
 */
string manacher(const string& s) {
    const char bogus = '#';
    string t;
    fe(c, s) {
        assert(c != bogus);
        t.pb(bogus);
        t.pb(c);
    }
    t.pb(bogus);

    // t has a length of 2*n+1
    ll n = lg(s), m = lg(t);
    assert(m == 2 * n + 1);

    const VLL radii = get_radii(t);  // careful - radius in terms of new string

    VVLL can_reach(m);
    rep(i, 0, m) {
        can_reach[i - radii[i]].pb(i);
    }

    VLL longest_starting(n);  // in terms of n
    ll farthest = 0;
    rep(i, 0, m) {
        fe(to, can_reach[i]) {
            upmax(farthest, to);
        }
        if (i % 2 == 1) {
            longest_starting[i / 2] = (farthest - i) + 1;
        }
    }

    auto big = max_element(all(radii));
    ll best_radius = *big;
    ll best_ind = big - radii.begin() - best_radius;

    string t_ans = t.substr(best_ind, (best_radius * 2) + 1);
    string s_ans;
    fe(c, t_ans) {
        if (c == bogus) continue;
        s_ans.pb(c);
    }

    return s_ans;
}
