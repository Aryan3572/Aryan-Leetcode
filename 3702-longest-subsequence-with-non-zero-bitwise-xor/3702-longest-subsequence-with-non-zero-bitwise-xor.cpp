class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int xorAll = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            xorAll ^= num;

            if (num != 0) {
                hasNonZero = true;
            }
        }

        // Entire array has non-zero XOR
        if (xorAll != 0) {
            return nums.size();
        }

        // XOR is zero, but we can remove one non-zero element
        if (hasNonZero) {
            return nums.size() - 1;
        }

        // All elements are zero
        return 0;
    }
};