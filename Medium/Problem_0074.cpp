class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(); int n=mat[0].size();
        int low=0 ,high=m*n-1;int mid;int row,col;
        while(low<=high){
            mid=(low+high)>>1;
            row=mid/n; col=mid%n;
            if(mat[row][col]==target){
                return true;
            }
            else if (mat[row][col]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return false;
    }
};
