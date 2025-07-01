
const int N = 1e5;
ll seg[4 * N];  

void build(vector<ll> &arr, ll node, ll start, ll end) {
    if (start == end) {
        seg[node] = arr[start];  
    } else {
        ll mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        seg[node] = seg[2 * node] + seg[2 * node + 1]; // change this line for different operations
        // For example, for min: seg[node] = gcd(seg[2 * node], seg[2 * node + 1]);
    }
}

ll query(ll node, ll start, ll end, ll l, ll r) {
    if (r < start || end < l) return 0;  
    if (l <= start && end <= r) return seg[node]; 
    ll mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r); // change this line for different operations
}

void update(vector<ll> &arr, ll node, ll start, ll end, ll idx, ll val) {
    if (start == end) {
        arr[idx] = val;
        seg[node] = val;
    } else {
        ll mid = (start + end) / 2;
        if (idx <= mid) {
            update(arr, 2 * node, start, mid, idx, val);
        } 
        else {
            update(arr, 2 * node + 1, mid + 1, end, idx, val);
        }
        seg[node] = seg[2 * node] + seg[2 * node + 1]; // change this line for different operations
    }
}
//build(arr, 1, 0, n - 1); 
//update(arr, 1, 0, n - 1, idx - 1, val); 
//query(1, 0, n - 1, l - 1, r - 1)
