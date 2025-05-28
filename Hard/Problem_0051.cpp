class Solution {
    bool safe(vector<vector<bool>>&matrix,int row,int col){
        for(int i =0 ; i<row; i++){
            for(int j=0 ; j<matrix.size() ; j++){
                if(col == j && matrix[i][j]==true)return false;
                else if(matrix[i][j]==true && row- col == i-j  )return false;
                else if(matrix[i][j]==true && row+ col == i+j  )return false;
            }
        }
        return true;
    }
    void helper(vector<vector<bool>>&matrix, vector<vector<string>>&ans,int row){
        int n= matrix.size();
        if(row==n){
            vector<string>ttemp;
            for(int i=0 ; i<n ; i++){
                string str = "";
                for(int j=0 ; j<n ; j++){
                    if(matrix[i][j]==true){
                        str+="Q";
                    }
                    else{
                        str+=".";
                    }
                }
                ttemp.push_back(str);
            }
            ans.push_back(ttemp);return;
        }
        for(int i=0 ; i<n ; i++){
            if(safe(matrix,row,i)){
                matrix[row][i] = true;
                helper(matrix,ans,row+1);
                matrix[row][i] = false;
            }
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>>matrix; 
        for(int i=0 ; i<n ; i++){
            vector<bool>temp;
            for(int j=0 ; j<n ; j++){
                temp.push_back(false);
            }
            matrix.push_back(temp);
        }
        int cnt=0 ; 
        vector<vector<string>>ans;
        helper(matrix, ans,0);
        return ans;
    }
};
