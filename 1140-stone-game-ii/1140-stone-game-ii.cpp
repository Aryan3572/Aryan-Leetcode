class Solution {
public:
    int solve(int index, int M, vector<int>& piles,
              vector<int>& suffix, vector<vector<int>>& dp) {

        int n = piles.size();

        if (index >= n)
            return 0;

        if (dp[index][M] != -1)
            return dp[index][M];

        int ans = 0;

        // Can take X piles where X <= 2*M
        for (int X = 1; X <= 2 * M && index + X <= n; X++) {

            // Total stones remaining from index
            // minus what Bob can get
            int current = suffix[index] -
                          solve(index + X, max(M, X),
                                piles, suffix, dp);

            ans = max(ans, current);
        }

        return dp[index][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = sum of piles[i...n-1]
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles, suffix, dp);
    }
};