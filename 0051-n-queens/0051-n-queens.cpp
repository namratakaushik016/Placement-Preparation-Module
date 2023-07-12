class Solution {
public:

void addSol(vector<vector<int>>&board,vector<vector<string>> &ans, int n){
    vector<string> t;
    for(int i=0;i<n;i++){
        string s;
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
                s.push_back('Q');
            }
            else{
                s.push_back('.');
            }
        }
        t.push_back(s);
    }
    ans.push_back(t);
}

bool isSf(int row,int col, vector<vector<int>>&board, int n ){
    int x=row;
    int y=col;
    while(y>=0){
        if(board[x][y--]==1){
            return false;
        }
    }
   x=row;
    y=col;
    while(y>=0 && x>=0){
        if(board[x--][y--]==1){
            return false;
        }
    }
       x=row;
    y=col;
    while(y>=0 && x<n){
        if(board[x++][y--]==1){
            return false;
        }
    }
    return true;
}









void solve(int col,vector<vector<string>> &ans,vector<vector<int>>&board, int n){
    if(col==n){
        addSol(board,ans, n);
        return ;
    }

    for(int row=0; row<n; row++){
        if(isSf(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,ans,board,n);
            board[row][col]=0;
        }
    }
}



    vector<vector<string>> solveNQueens(int n) {
     vector<vector<int>> board (n,vector<int>(n,0));
     vector<vector<string>>ans;
     solve(0,ans,board,n);
    return ans;
    }
};