//
// Created by amir on 12/18/22.
//
//un completed zero test case pass;

#include<bits/stdc++.h>

bool isValid(int x,int y,int size){
    if((x>=0 and x<size) and (y>=0 and y<size)){
        return true;
    }else{
        return false;
    }
}

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    // Write your code here

    //knight position
    int kx = knightPosition.first;//cordinates are 1 index we convert to zero
    int ky = knightPosition.second;

    //targest position
    int tx= targetPosition.first;
    int ty = targetPosition.second;

    //if both postion is same in starting
    if(kx==tx and ky==ty){
        return 0;
    }
    //init 2D Array for Track Visited Postion;
    vector<vector<bool>>visited(size+1,vector<bool>(size+1,false));

    //init queue of pair ;
    queue<pair<int,int>>q;
    q.push({kx,ky}); //push starting position of knight;
    visited[kx][ky]=true;

    int ans = 0;

    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        ans++;//increase answer or step;
        // 8 step of knight
        int sx[8] ={ -2, -1, 1, 2, -2, -1, 1, 2 };//step of x-axis
        int sy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };//step of y-axis;

        // possible step of cordinates;
        for(int i=0;i<8;i++){
            int px   = front.first+sx[i];
            int py = front.second+sy[i];
            //check is both position same or not - target and possible step
            if(px==tx and py == ty){
                return ans;
            }
            //checking valid
            if(isValid(px,py,size)and visited[px][py]==false){
                q.push({px,py});
                visited[px][py]=true;
            }
        }

    }

    return 0;






}
