const ll base = 31;            
const ll mod = 1e9 + 9;       

vector<ll> computePowers(int n) {
    vector<ll> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = (p[i - 1] * base) % mod;
    }
    return p;
}

vector<ll> computePrefixHash(const string &s, const vector<ll> &p) {
    int n = s.size();
    vector<ll> h(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        ll val = s[i] - 'a' + 1;
        h[i + 1] = (h[i] + val * p[i]) % mod;
    }
    return h;
}

ll getSubstrHash(const vector<ll> &h, const vector<ll> &p, int l, int r) {
    ll hashVal = (h[r + 1] - h[l] + mod) % mod;
    return (hashVal * p[p.size() - l - 1]) % mod; 
}

vector<int> rabinKarp(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return {};

    vector<ll> p = computePowers(max(n, m) + 1);
    vector<ll> hashText = computePrefixHash(text, p);
    vector<ll> hashPattern = computePrefixHash(pattern, p);

    ll patternHash = getSubstrHash(hashPattern, p, 0, m - 1);
    vector<int> positions;

    for (int i = 0; i <= n - m; i++) {
        ll subHash = getSubstrHash(hashText, p, i, i + m - 1);
        if (subHash == patternHash && text.substr(i, m) == pattern) {
            positions.push_back(i);
        }
    }

    return positions;
}
