// LeetCode 977 - Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int index = n - 1;
        while (left <= right) {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if (a > b) {
                result[index--] = a;
                left++;
            } else {
                result[index--] = b;
                right--;
            }
        }
        return result;
    }
};
