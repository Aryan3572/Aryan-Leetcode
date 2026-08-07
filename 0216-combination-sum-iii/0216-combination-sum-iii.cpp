class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> nums;
        solve(1, n, k , nums, result);
        return result;
    }
    void solve(int curr, int sum, int k, vector<int>&nums, vector<vector<int>>& result)
    {
        if(sum == 0 && nums.size() == k)
        {
            result.push_back(nums);
            return;
        }
        if(sum <= 0 || nums.size() > k) return;

        for(int i = curr; i <= 9;i++)
        {
            if(i <= sum)
            {
                nums.push_back(i);

                solve(i+1, sum - i, k, nums, result);
                nums.pop_back();
            }
            else{
                break;
            }
        }

    }
};