class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> result;

        solve(0, candidates, target , curr, result);

        return result;
    }
    void solve(int index, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(curr);
            return;
        }

        if(index == candidates.size())
        {
            return;
        }

        if(candidates[index] <= target)
        {
            curr.push_back(candidates[index]);

            solve(index, candidates, target - candidates[index], curr, result);

            curr.pop_back();
        }

        solve(index + 1, candidates , target, curr, result);
    }
};