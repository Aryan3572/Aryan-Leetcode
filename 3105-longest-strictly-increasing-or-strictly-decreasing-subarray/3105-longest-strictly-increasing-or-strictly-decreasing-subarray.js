/**
 * @param {number[]} nums
 * @return {number}
 */
var longestMonotonicSubarray = function(nums) {
    let best = 1, up = 1 , down = 1;
    for(let i = 1;i<nums.length;i++)
    {
        up = nums[i-1] < nums[i] ? up + 1 : 1;
        down = nums[i - 1] > nums[i] ? down + 1 : 1;
        best = Math.max(best, up, down);
    }
    return best;
};