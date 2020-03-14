string binary(ll x) {
    if (x == 0) return "";
    if (x % 2) return binary(x/2) + "1";
    else return binary(x/2) + "0";
}