int par[N], siz[N];

void setup(int n) {
    for (int i = 0; i <= n ; i++) par[i] = i;
    for (int i = 0; i <= n; i++) siz[i] = 1;
}

int find(int x) {
    while (x != par[x])x = par[x];
    return x;
}

bool same(int a, int b) {return find(a) == find(b);}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (siz[a] < siz[b])swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}
