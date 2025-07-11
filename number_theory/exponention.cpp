ll binPow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;  
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}