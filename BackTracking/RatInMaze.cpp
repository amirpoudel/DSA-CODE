//
// Created by amir on 9/12/22.
//
//Rate In Maze using Backtracking




//priority move - Lexicographical order print - DLRU

bool isSafeMove(int x,int y ,vector < vector < int >> & arr,vector<vector<bool>> &isVisited,int n){
    if( ((x>=0 and x<n) and(y>=0 and y<n))and (arr[x][y]==1 and isVisited[x][y]!=1)){
        return true;
    }else{
        return false;
    }
}

void solve(int x, int y,vector<vector<int>>&arr,int n,vector<string>&answer,vector<vector<bool>>&isVisited,string path){

    //Base case
    if(x==n-1 and y==n-1){
        answer.push_back(path);
        return;
    }

    isVisited[x][y]=1;

    // Down

    if(isSafeMove(x+1,y,arr,isVisited,n)){

        solve(x+1,y,arr,n,answer,isVisited,path+'D');

    }

    // Left

    if(isSafeMove(x,y-1,arr,isVisited,n)){

        solve(x,y-1,arr,n,answer,isVisited,path+'L');


    }

    // Right

    if(isSafeMove(x,y+1,arr,isVisited,n)){

        solve(x,y+1,arr,n,answer,isVisited,path+'R');


    }

    // Up

    if(isSafeMove(x-1,y,arr,isVisited,n)){

        solve(x-1,y,arr,n,answer,isVisited,path+'U');


    }
    //backTracking
    isVisited[x][y]=0;





}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> answer;
    vector<vector<bool>> isVisited(n,vector<bool>(n,0));
    string path = "";
    if(arr[0][0]==0){
        answer.push_back(path);
        return answer;
    }
    solve(0,0,arr,n,answer,isVisited,path);
}