class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);

        arr[0] = nums[0];
        arr[n-1] = nums[1];

        int index = 0, revIndex = n - 1;
        for(int i = 2;i < n;i++)
        {
            if(arr[index] > arr[revIndex])
            {
                arr[++index] = nums[i];
            }
            else
            {
                arr[--revIndex] = nums[i];
            }
        }
        reverse(arr.begin() + revIndex, arr.end());
        return arr;
    }
};