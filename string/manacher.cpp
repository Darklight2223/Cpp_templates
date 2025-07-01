vector<int> manacher(string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> p(n, 0);
    int c = 0, r = 0; 
    for (int i = 0; i < n; i++) {
        int mirror = 2 * c - i; 
        if (i < r) {
            p[i] = min(r - i, p[mirror]);
        }
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && s[i + p[i] + 1] == s[i - p[i] - 1]) {
            p[i]++;
        }

        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    return p;
}
