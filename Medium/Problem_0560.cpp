class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();int s=0;int cnt=0;
        if(n==1 && nums[0]!=k)return 0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0 ; i<n; i++){
            s+=nums[i];
            int r=s-k;
            cnt+=mp[r];
            mp[s]+=1;
        }
        return cnt;
    }
};
