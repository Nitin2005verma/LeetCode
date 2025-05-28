#include<bits/stdc++.h>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        map<int,int>hash;
        for (int i=0 ; i<=n ; i++){
            hash[nums[i]]++;
        }
        auto it=hash.begin();
        while(it!=hash.end()){
            if(it->second>1){
                return it->first;
            }
            it++;
        }
        return 0;
    }
};
