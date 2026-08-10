class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true means the current player can win
        // with i stones remaining.
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                // If removing j*j stones leaves the opponent
                // in a losing position, current player wins.
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};