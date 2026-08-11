class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        // Step 1: Find the sequential prefix sum
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } 
            else {
                break;
            }
        }

        // Step 2: Store all numbers in a set
        unordered_set<int> st(nums.begin(), nums.end());

        // Step 3: Find the smallest missing integer >= sum
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};