//
// Created by amir on 9/13/22.
//



void insertSolution(vector<vector<int>>&ans,vector<vector<int>>&board,int n){

    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);

        }
    }
    ans.push_back(temp);

}

bool isSafe(int row,int col,vector<vector<int>>&board,int n){
    int x = row;
    int y = col;

    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    x = row;
    y = col;

    while(x>=0 and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    while(x<n and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }

    return true;

}

void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    //base case
    if(col==n){
        insertSolution(ans,board,n);
        return;
    }

    //solve one case other recursion will solve
    for(int row=0;row<n;row++){

        if(isSafe(row,col,board, n)){
            board[row][col]=1;
            solve(col+1,board,ans,n);
            //backtracking
            board[row][col]=0;
        }

    }


}


vector<vector<int>> nQueens(int n)
{
    // Write your code here
    //creating n*n board

    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;
    solve(0,board,ans,n);
    return ans;

}