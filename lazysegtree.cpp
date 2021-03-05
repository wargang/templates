int st[4 * N], lazy[4 * N];
void build(int node, int ss, int se) {
    if (ss == se) {
        st[node] = arr[ss];
        //++++++++++++++++++++++++

        return;
    }
    int l = 2 * node + 1, r = 2 * node + 2;
    int mid = (ss + se) / 2;
    build(2 * node + 1, ss, mid);
    build(2 * node + 2, mid + 1, se);
    st[node] = st[l] + st[r];
    //+++++++++++++++++++++++++++

}

void update(int node, int ss, int se, int qs, int qe, int val) {
    int l = 2 * node + 1, r = 2 * node + 2;

    if (lazy[node] != -1) {
        int dx = lazy[node];
        //+++++++++++++++++++++++++
        st[node] += (se - ss + 1) * dx; // update it
        lazy[node] = -1;
        if (ss != se) {
            lazy[l] += dx;          // mark childs as lazy
            lazy[r] += dx;
        }
    }
    if (ss > qe || se < qs)  // Current segment is not within range [l, r]
        return ;

    if (ss >= qs && se <= qe) {
        // ++++++++++++++++++++++++
        st[node] += (se - ss + 1) * val;
        if (ss != se) {
            // Not leaf node
            lazy[l] += val;
            lazy[r] += val;
        }
        return;
    }

    int mid = (ss + se) / 2;
    update(l, ss, mid, qs, qe, val);
    update(r, mid + 1, se, qs, qe, val);

    st[node] = st[l] + st[r];
    // ++++++++++++++++++++++++++
}

int query(int node, int ss, int se, int qs, int qe) {
    int l = 2 * node + 1, r = 2 * node + 2;

    if (ss > qe || se < qs) // Out of range
        return 0;

    if (lazy[node] != -1) {
        int dx = lazy[node];
        // ++++++++++++++++++++++++++++
        st[node] += (se - ss + 1) * dx;
        lazy[node] = -1;
        if (ss != se) {
            lazy[l] += dx;
            lazy[r] += dx;
        }
    }


    if (qs <= ss and se <= qe)
        return st[node];

    int mid = (ss + se) / 2;
    int left = query(l, ss, mid, qs, qe);
    int right = query(r, mid + 1, se, qs, qe);
    // ++++++++++++++++++++++++++
    return left + right;
}
