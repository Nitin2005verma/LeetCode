class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<vector<char>>temp(numRows,vector<char>());
        int i=0; int n=s.length();
        int rev=0;int level=0;
        while(i<n){
            temp[level].push_back(s[i]);
            if(level==numRows-1){
                rev=1;
            }
            else if(level==0){
                rev=0;
            }
            if(rev==0){
                level++;
            }
            else{
                level--;
            }
            
            i++;
        }
        //----------------------
        string ans="";
        for (auto it: temp){
            for (int i=0; i<it.size(); i++){
                ans+=it[i];
            }
        }
        return ans;

    }
};
