int EEA(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = EEA(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// 1. Fermat's little theorem
// a^(p-1) = 1 (mod p) -> a * a^(p-2) = 1 (mod p)
// NOTE: p must be a prime number

// 2. the extension of Euclidean Algorithm
// solve ax + py = 1 (mod p)
int mod_inv(int a, int m) {
    int x, y;
    int d = EEA(a, m, x, y);
    if (d != 1)
        return -1;
    x = (x % m + m) % m;
    return x;
}
