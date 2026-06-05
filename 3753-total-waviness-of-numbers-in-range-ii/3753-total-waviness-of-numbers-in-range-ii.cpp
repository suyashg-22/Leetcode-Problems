using ll = long long;

class Solution {
public:
    // Added an extra dimension [2] to store {waviness_sum, valid_count}
    ll dp[16][2][2][11][11][2];

    pair<ll, ll> rec(int level, bool tight, bool start, int p1, int p2, string &s) {
        // Base case: 0 waviness, 1 valid number formed
        if(level == s.size()) return {0, 1}; 

        if(dp[level][tight][start][p1][p2][0] != -1)
            return {dp[level][tight][start][p1][p2][0], dp[level][tight][start][p1][p2][1]};

        ll ans_wave = 0;
        ll ans_count = 0;

        int limit = tight ? s[level] - '0' : 9;

        for(int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if(!start && d == 0) {
                pair<ll, ll> res = rec(level + 1, ntight, 0, 10, 10, s);
                ans_wave += res.first;
                ans_count += res.second;
            }
            else {
                if(p1 == 10 || p2 == 10) {
                    pair<ll, ll> res = rec(level + 1, ntight, 1, d, p1, s);
                    ans_wave += res.first;
                    ans_count += res.second;
                }
                else {
                    ll add = 0;

                    if((p1 > p2 && p1 > d) ||
                       (p1 < p2 && p1 < d))
                        add = 1;

                    pair<ll, ll> res = rec(level + 1, ntight, 1, d, p1, s);
                    
                    // Core Fix: Multiply `add` by the number of valid suffixes (res.second)
                    ans_wave += res.first + (add * res.second);
                    ans_count += res.second;
                }
            }
        }

        dp[level][tight][start][p1][p2][0] = ans_wave;
        dp[level][tight][start][p1][p2][1] = ans_count;
        return {ans_wave, ans_count};
    }

    long long solve(long long x) {
        if(x <= 0) return 0;

        string s = to_string(x);

        memset(dp, -1, sizeof(dp));

        // Return only the waviness sum (.first) for the final answer
        return rec(0, 1, 0, 10, 10, s).first; 
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};