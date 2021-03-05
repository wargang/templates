int BIT[N + 10], n;

int query(int idx) {
    int ans = MAX;
    for (; idx > 0; idx -= idx & (-idx)) {
        ans = min(ans, BIT[idx]);
    }
    return ans;
}

void update(int idx, int val) {
    for (; idx <= n; idx += idx & (-idx))
        BIT[idx] = min(BIT[idx], val);
}
