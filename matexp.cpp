const int  md = 2;
        
void mul(int a[md][md], int b[md][md]) {
    int res[md][md];
    rep(i, md) {
        rep(j, md) {
            res[i][j] = 0;
            rep(k, md) {
                res[i][j] = (res[i][j] % mod + (a[i][k] % mod * b[k][j] % mod) % mod) % mod;
            }
        }
    }
    rep(i, md)
    rep(j, md)
    a[i][j] = res[i][j];
}

// 1. remember in base its top to bottom
// 2. SET K
// 3. 

int fib(int n) {
    int base[md][1] = {1, 1}; // +++++++++++++++++

    if (n == 1 || n == 2) // +++++++++++++++++++++
        return 1;

    int identity[md][md]; set(identity);
    rep(i, md) rep(j, md) if(i==j) identity[i][j]=1;

    int start[md][md] = {{1, 1}, {1, 0}}; // +++++++++++++++++
    int k = n - 2;                         // ++++++++++++++++
    while (k) {
        if (k & 1)
        {mul(identity, start); k--; }
        else
        {mul(start, start); k /= 2; }
    }
    int res[md][1];
    for (int i = 0; i < md; i++) {
        for (int j = 0; j < 1; j++) {
            res[i][j] = 0;
            for (int k = 0; k < md; k++)
                res[i][j] = (res[i][j] % mod + (identity[i][k] % mod * base[k][j] % mod) % mod) % mod;
        }
    }
    return res[0][0];
}
