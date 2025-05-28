class Solution {
public:
long long reqtime(int k,vector<int>nums){
    long long time=0;
    for (int i=0 ; i<nums.size(); i++){
        long long temp;
        if(nums[i]%k==0){
            temp=nums[i]/k;
        }
        else{
            temp=nums[i]/k +1;
        }
        time+=temp;
    }
    return time;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mx=0;
        for (int i=0 ; i<n ; i++){
            mx=max(mx,piles[i]);
        }
        int low=1,high=mx;int mid;int ans=mx;
        while(low<=high){
            mid=(low+high)/2;
            if(reqtime(mid,piles)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};
