template <typename T>
pair<T, T> intersection(const pair<T, T>& A, const pair<T, T>& B) {
    pair<T, T> res = {max(A.first, B.first), min(A.second, B.second)};
    // if res.first > res.second no intersection
    return res;
}

template <typename T>
bool intersect(const pair<T, T>& A, const pair<T, T>& B) {
    const auto res = intersection(A, B);
    return res.first <= res.second;
}
