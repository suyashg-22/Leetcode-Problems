class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) return {-1, -1};

        // Step 1: Sieve of Eratosthenes up to right
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= right; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i)
                    isPrime[j] = false;
            }
        }

        // Step 2: Collect primes in [left, right]
        vector<int> primes;
        for (int i = max(2, left); i <= right; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }

        // Step 3: Find the pair with the smallest gap
        if (primes.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> ans = {-1, -1};

        for (int i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                ans = {primes[i - 1], primes[i]};
            }
        }

        return ans;
    }
};
