int arr[N], n, q;
vi st[4 * N];

void build( int node, int ss, int se) {
    if (ss == se) {
        st[node].pb(arr[ss]);
        return ;
    }
    int mid = (ss + se) / 2;
    int l = 2 * node + 1, r = 2 * node + 2;

    build(l, ss, mid);
    build(r, mid + 1, se);
    merge(all(st[l]), all(st[r]), back_inserter(st[node]));
}

int query(int node, int ss, int se, int qs, int qe, int k) {
    int l = 2 * node + 1, r = 2 * node + 2;
    if (ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe) {
        int x = upper_bound(all(st[node]), k) - st[node].begin();
        return st[node].size() - x;
    }
    int mid = (ss + se) / 2;
    return query(l, ss, mid, qs, qe, k) + query(r, mid + 1, se, qs, qe, k);

}
