vector<int> primes, spf;
vector<bool> is_prime;

void sieve(int n) {
    is_prime.assign(n + 1, true);
    spf.assign(n + 1, 0);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            spf[i] = i;
            for (ll j = 1LL * i * i; j <= n; j += i) {
                is_prime[j] = false;
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}
