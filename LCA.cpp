const int LOG = log2(N) + 1;
int d[N], up[N][LOG + 1];

void dfs(int i, int p) {
    d[i] = d[p] + 1;     //  ////////////  do this d[0] = -1;
    up[i][0] = p;
    for (int j = 1; j <= LOG; j++) {
        up[i][j] = up[up[i][j - 1]][j - 1];
    }
    for (int j : adj[i]) {
        if (j != p) dfs(j, i);
    }
}

int lca(int a, int b) {
    if (d[b] > d[a]) swap(a, b);
    for (int i = LOG; i >= 0; i--) {
        if (d[a] - (1 << i) >= d[b]) {
            a = up[a][i];
        }
    }
    if (a == b) return a;
    for (int i = LOG; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int get_dist(int a, int b) {
    return d[a] + d[b] - 2 * d[lca(a, b)];
}
