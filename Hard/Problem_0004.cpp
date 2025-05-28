class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        
        for (int i = 0; i < m; i++) {
            ans.push_back(nums1[i]);
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(nums2[i]);
        }
        
        sort(ans.begin(), ans.end());
        
        double median;
        int total = m + n;
        
        if (total % 2 == 0) {
            median = (ans[total / 2 - 1] + ans[total / 2]) / 2.0; // Corrected division to ensure floating-point result
        } else {
            median = ans[total / 2];
        }
        
        return median;
    }
};
