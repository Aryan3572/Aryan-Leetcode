class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);
        
        int diff = solve(stoneValue , 0, dp);
        if(diff>0)
        {
            return "Alice";
        }
        else if(diff < 0)
        {
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
    int solve(vector<int>& stoneValue , int i, vector<int>& dp)
    {
        if(i >= stoneValue.size())
        {
            return 0;
        }
        if(dp[i] != INT_MIN)
        {
            return dp[i];
        }

        int ans = INT_MIN;
        int sum = 0;

        for(int k = 0;k < 3 && i + k < stoneValue.size();k++)
        {
            sum += stoneValue[i + k];
            ans = max(ans , sum - solve(stoneValue , i + k + 1, dp));
        }
        return dp[i] = ans;
    }
};