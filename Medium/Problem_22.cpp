class Solution {
    void helper(string curr,int cnt_in,int cnt_out,int n ,vector<string>&ans){
        if(cnt_in==n){
            if(cnt_out==n){
                ans.push_back(curr);return;
            }
            while(cnt_out!=n){
                curr+=")";cnt_out++;
            }
            ans.push_back(curr);return;
        }
        if(cnt_in<=cnt_out){
            helper(curr+"(", cnt_in+1,cnt_out, n , ans);
        }
        else{
            helper(curr+"(", cnt_in+1,cnt_out,n,ans);
            helper(curr+")" , cnt_in,cnt_out+1 , n, ans);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        int cnt_in =0; int cnt_out=0 ; string curr= "";
        vector<string>ans;
        helper(curr,cnt_in,cnt_out,n,ans);
        return ans;
    }
};
