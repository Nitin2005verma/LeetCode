class Solution {
public:

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        vector<int>max_in_col;
        vector<int>max_in_row;int temp;
        for (int col=0 ; col<n ; col++){
            temp=0;
            for (int row=0 ; row<n ; row++){
                temp=max(temp,grid[row][col]);
            }
            max_in_col.push_back(temp);
        }
        for (int row=0 ; row<n ; row++){
            temp=0;
            for (int col=0 ; col<n ; col++){
                temp=max(temp,grid[row][col]);
            }
            max_in_row.push_back(temp);
        }
        int sel1=0,sel2=0;//1 from row 2 from col
        int fin;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                sel1=max_in_row[i];
                sel2=max_in_col[j];
                fin=min(sel1,sel2)-grid[i][j];
                cnt+=fin;
            }
        }
        return cnt;
        


    }
};
