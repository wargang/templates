vi primes;
void SieveOfEratosthenes() {
    bool prime[N];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p < N ; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i < N ; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p < N ; p++)
        if (prime[p])
            primes.pb(p);
}
