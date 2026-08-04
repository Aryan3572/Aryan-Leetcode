class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        
        unordered_set<int> st;

        for(int num : nums)
        {
            minimum = min(minimum, num);
            maximum = max(maximum, num);

            st.insert(num);
        }

        vector<int> ans;

        for(int i = minimum + 1;i<maximum;i++)
        {
            if(st.find(i) == st.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};