class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;int cnt=0;
        // int mn=INT_MAX;int mx=INT_MIN;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            // mn=min(mn,nums[i]);
            // mx=max(mx,nums[i]);
        }
        int mxcnt=0;
        int last=INT_MIN;
        for(auto it: mp){
            if(last==INT_MIN){
                cnt++;
                mxcnt=max(mxcnt,cnt);
                last=it.first;
            }
            else{
                int pre=it.first;
                if(pre-1==last){
                    cnt++;
                    mxcnt=max(mxcnt,cnt);
                    last=pre;
                }
                else{
                    mxcnt=max(mxcnt,cnt);
                    last=pre;
                    cnt=1;
                }
            }
        }
        return mxcnt;
    }
};
