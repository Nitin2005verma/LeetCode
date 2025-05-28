class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int k=1; int i=0;int m=target.size();
        while(k<=n && i<m){
            if(k !=target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                k++;
            }
            else{
                ans.push_back("Push");
                i++;k++;
            }
        }
        return ans;
    }
};
