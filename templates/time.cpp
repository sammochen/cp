namespace Time {

ll getDateOrd(const string& date) {
    // MM-DD, 1-indexed
    ll m = stoll(date.substr(0, 2));
    ll d = stoll(date.substr(3, 2));

    VLL days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ll sum = d - 1;
    rep(i, 0, m - 1) {
        sum += days[i];
    }
    return sum;
}

}  // namespace Time
