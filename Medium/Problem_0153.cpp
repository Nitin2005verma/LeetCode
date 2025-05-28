class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();int low=0,high=n-1;int mid;int ans=INT_MAX;
        while (low<=high){
            mid= (low+high)/2;
            if (nums[mid]>=nums[low]){
                //left sorted
                ans= min(ans,nums[low]);
                low = mid +1 ;
            }
            else{
                ans=min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};
