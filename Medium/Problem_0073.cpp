class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,int>row;// Better
        unordered_map<int,int>col;// TC:O(m*n)
        for(int i=0; i<m; i++){  //SC:O(m+n)
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    if(row.find(i)==row.end()) row[i]++;
                    if(col.find(j)==col.end()) col[j]++;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i] !=0 || col[j] !=0){
                    mat[i][j]=0;
                }
            }
        }
        
    }
};
