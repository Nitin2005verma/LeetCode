class Solution {
    void helper(set<vector<int>>& ans, vector<int>& candidates, int target, vector<int>& curr,int ptr) {
        if(ptr>=candidates.size())return;
        if(target==0){
            ans.insert(curr);
            return;
        }
        if(target<0)return;
        curr.push_back(candidates[ptr]);
        helper(ans,candidates,target- candidates[ptr], curr, ptr);
        curr.pop_back();
        helper(ans,candidates,target,curr,ptr+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>>ans;vector<int>curr;
        helper(ans,candidates,target,curr,0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
