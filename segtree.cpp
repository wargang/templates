int n, q, arr[N], st[4 * N];

void build(int node, int ss, int se) {
    int l = 2 * node + 1, r = 2 * node + 2;
    if (ss == se) {
        // +++++++++++++

        return;
    }
    if (ss > se)
        return ;
    int mid = (ss + se) / 2;
    build(l, ss, mid);
    build(r, mid + 1, se);
    //+++++++++++++++

}

void update(int node, int ss, int se, int i, int val) {
    int l = 2 * node + 1, r = 2 * node + 2;
    if (ss == se && ss == i) {
        arr[i] = val;
        //++++++++++++++++

        return;
    }
    if (i > se || i < ss)
        return ;

    int mid = (ss + se) / 2;
    update(l, ss, mid, i, val);
    update(r, mid + 1, se, i, val);
    //+++++++++++++

}

struct Node query(int node, int ss, int se, int qs, int qe) {
    int l = 2 * node + 1, r = 2 * node + 2;
    if (ss > qe || se < qs) {
        //++++++++++++

    }

    if (qs <= ss && se <= qe)
        return st[node];

    int mid = (ss + se) / 2;
    int left = query(l, ss, mid, qs, qe);
    int right = query(r, mid + 1, se, qs, qe);
    //++++++++++++

}
