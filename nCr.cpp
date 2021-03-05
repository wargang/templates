int fact[N];
void pre(){
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}
int nCr(int n, int r) {
    if (n < 0 || r < 0)
        return 0ll;
    if (r > n)
        return 0ll;
    return (fact[n] * mpow(fact[n - r], mod - 2) % mod * mpow(fact[r], mod - 2) % mod) % mod;
}
