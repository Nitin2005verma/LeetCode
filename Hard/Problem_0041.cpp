class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Mark numbers out of range and negatives as n + 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Use index as a hash map
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val <= n) {
                nums[val - 1] = -abs(nums[val - 1]);
            }
        }

        // Step 3: Find the first positive number
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // If all numbers from 1 to n are present
        return n + 1;
    }
};
