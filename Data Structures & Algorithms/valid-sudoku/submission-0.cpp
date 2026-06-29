class Solution {
public:
    bool f(int row , int col ,vector<vector<char>>& board ){
        vector<int> mpp(9,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row+i][col+j]!='.' && mpp[board[row+i][col+j]-'1']==1){
                    return false;
                }
                else if(board[row+i][col+j]!='.') {
                    mpp[board[row+i][col+j]-'1']++;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            vector<int> mpp(9,0);
            for(int j=0;j<m;j++){
                if(board[i][j]!='.' && mpp[board[i][j]-'1']==1){
                    return false;
                }
                else if(board[i][j]!='.') {
                    mpp[board[i][j]-'1']++;
                }
            }
        }
        for(int i=0;i<n;i++){
            vector<int> mpp(9,0);
            for(int j=0;j<m;j++){
                if(board[j][i]!='.' && mpp[board[j][i]-'1']==1){
                    return false;
                }
                else if(board[j][i]!='.') {
                    mpp[board[j][i]-'1']++;
                }
            }
        }
        // i have to explore 9 sub-box...
        vector<int> row={0,3,6};
        vector<int> col={0,3,6};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(f(row[i],col[j],board)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
