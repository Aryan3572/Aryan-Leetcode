class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin() , candidates.end());
        vector<int> curr;
        vector<vector<int>> result;

        solve(0, candidates, target , curr , result);

        return result;
    }

    void solve(int index, vector<int>& candidates , int target , vector<int>& curr, vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(curr);
            return;
        }

        for(int i = index;i<candidates.size();i++)
        {
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            
            
            if(candidates[i] > target) break;

            curr.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], curr, result);

            curr.pop_back();
        }
    }
};