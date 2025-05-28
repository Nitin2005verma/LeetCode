class Solution {
    bool issafe(char ch, int row, int col,vector<vector<char>>& board){
        for(int i=0 ; i<9 ; i++){
            if(board[i][col] == ch)return false;
        }
        for(int i=0 ; i<9 ; i++){
            if(board[row][i] == ch)return false;
        }
        // Check 3x3 sub-boxes
        int b_row=row/3;int b_col=col/3;
        for(int i=b_row*3 ; i<(b_row+1)*3 ; i++){
            for(int j =b_col*3 ; j<(b_col+1)*3 ; j++){
                if(ch==board[i][j])return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9)return true;
        if(col==9){
            return helper(board, row + 1, 0);
        }
        if(board[row][col]!='.')return helper(board,row,col+1);
            
                for(int i=1 ; i<=9 ; i++){
                    if(issafe('0'+i,row,col,board)){
                        board[row][col]='0'+i;
                        if(helper(board,row,col+1))return true;
                        board[row][col]='.';
                    }
                }
            
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};
