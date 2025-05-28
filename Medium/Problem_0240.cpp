class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int low,high,mid;
        int n=mat[0].size();
        for (int i=0 ; i<mat.size(); i++){
            low=0 ; high=n-1;
            if(target>mat[i][high] || target<mat[i][0]){
                continue;
            }
            while(low<=high){
                mid=(low+high)/2;
                if(mat[i][mid]==target){
                    return true;
                }
                else if (mat[i][mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            
        }return false;
    }
};
