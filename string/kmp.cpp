vector<int> buildLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0; 
    for (int i = 1; i < n;) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmpSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = buildLPS(pattern);
    int i = 0; 
    int j = 0; 
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            return i - j; 
            // ans.push_back(i - j); // If you want to store all occurrences, use a vector to collect them.
            // j = lps[j - 1]; // Reset j to continue searching for more occurrences.
        } 
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } 
            else {
                i++;
            }
        }
    }
    return -1; 
}

