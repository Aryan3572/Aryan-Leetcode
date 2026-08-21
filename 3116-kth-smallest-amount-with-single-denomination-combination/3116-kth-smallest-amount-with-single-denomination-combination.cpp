class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(vector<int>& coins, long long x) {

        int n = coins.size();
        long long count = 0;

        // Generate all non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long long common = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    common = lcm(common, coins[i]);

                    // No multiple of common <= x
                    if (common > x) {
                        break;
                    }
                }
            }

            if (common > x)
                continue;

            long long multiples = x / common;

            // Odd number of elements -> add
            if (bits % 2 == 1)
                count += multiples;

            // Even number of elements -> subtract
            else
                count -= multiples;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        // Maximum possible answer
        long long high = 1LL * k * (*min_element(coins.begin(),
                                                   coins.end()));

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countNumbers(coins, mid) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};