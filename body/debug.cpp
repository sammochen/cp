// --------------------------------- DEBUG ---------------------------------
// clang-format off
namespace Debug {
const string open = "[", sep = ", ", close = "]";
struct Second {}; struct First : Second {};

template <typename T>
auto one(T t, First) -> decltype(cout << t, string()) { stringstream ss; ss << t; return ss.str(); }
template <typename T>
auto one(T t, Second) -> decltype(t.first, t.second, string()) { return open + one(t.first, First()) + ", " + one(t.second, First()) + close; }
template <typename T>
auto one(T t, Second) -> decltype(t.begin(), t.end(), string() ) { string ans = open; for (auto a : t) { ans += (ans == open ? "" : sep) + one(a, First()); } return ans + close; }

string mult() { return ""; }
template <typename A, typename... B>
string mult(A a, B... b) { return one(a, First()) + " " + mult(b...); }
}  // namespace Debug
#define debug(...) do { cout << Debug::mult("[" + string(#__VA_ARGS__) + "]:", __VA_ARGS__) << endl; } while (false)
// clang-format on
// --------------------------------- DEBUG ---------------------------------
