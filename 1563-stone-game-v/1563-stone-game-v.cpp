class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

    int solve(int l, int r) {

        // Only one stone -> cannot split
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int i = l; i < r; i++) {

            int leftSum = prefix[i + 1] - prefix[l];
            int rightSum = prefix[r + 1] - prefix[i + 1];

            if (leftSum < rightSum) {

                ans = max(ans,
                          leftSum + solve(l, i));
            }
            else if (leftSum > rightSum) {

                ans = max(ans,
                          rightSum + solve(i + 1, r));
            }
            else {

                ans = max(ans,
                          leftSum + max(
                              solve(l, i),
                              solve(i + 1, r)
                          ));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        n = stoneValue.size();

        // Prefix sum
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score Alice can obtain
        // from subarray l...r
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};