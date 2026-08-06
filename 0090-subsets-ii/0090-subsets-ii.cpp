class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        vector<vector<int>> result;

        solve(0, nums , curr, result);

        return result;
        
    }
    void solve(int index, vector<int>& nums , vector<int>& curr, vector<vector<int>>& result)
    {
            result.push_back(curr);

        for(int i = index; i < nums.size(); i++)
        {
            if(i > index && nums[i] == nums[i-1])
                continue;

            curr.push_back(nums[i]);

            solve(i + 1, nums, curr, result);

            curr.pop_back();
        }
    }
};