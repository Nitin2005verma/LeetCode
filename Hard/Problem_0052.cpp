
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
    void helper(int & cnt,vector<vector<bool>>&matrix, vector<vector<string>>&ans,int row){
        int n= matrix.size();
        if(row==n){
            cnt+=1;
        }
        for(int i=0 ; i<n ; i++){
            if(safe(matrix,row,i)){
                matrix[row][i] = true;
                helper(cnt,matrix,ans,row+1);
                matrix[row][i] = false;
            }
        }
        
    }
public:
    int totalNQueens(int n){
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
         helper(cnt,matrix, ans,0);
        return cnt;
    }
};
