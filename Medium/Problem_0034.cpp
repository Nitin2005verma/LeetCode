#include<bits/stdc++.h>
#include<algorithm>
class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {

        auto lb = lower_bound(nums.begin(), nums.end(),target);
        auto ub = upper_bound(nums.begin(), nums.end(),target);
        if (lb!=nums.end() && *lb==target ){
            int st = distance(nums.begin(), lb);
            int end = distance(nums.begin(), ub);
            return {st,end-1};
        }
        else{
            return {-1,-1};
        }
    }
};
