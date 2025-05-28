class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;int n=nums.size();
        sort(nums.begin(),nums.end());
        for (int i=1 ; i<n ; i++){
            if (nums[i]==nums[i-1]){
                ans.push_back(nums[i]);
            }
        }
            
        return ans;
    }
};
