class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int st=-1; int end=-1;int n=intervals.size();
        for(int i=0; i<n; i++){
            if(st==-1){
                st=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                if(intervals[i][0] > end ){
                    ans.push_back({st,end});
                    st=intervals[i][0];
                    end=intervals[i][1];
                }
                else{
                    end=max(end,intervals[i][1]);
                }
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};
