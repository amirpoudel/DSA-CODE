//
// Created by amirpoudel on 12/14/2022.
//

#include<bits/stdc++.h>


void dfsFloodFill(vector<vector<int>>&image,vector<vector<int>>&vis,int x, int y ,int newColor,int oldColor,int n,int m){


    if(x<0 or y<0 or x>=n or y>=m){
        return;
    }
    //change the color ;
    if(vis[x][y]==1 or image[x][y]!=oldColor){
        return;
    }

    image[x][y] = newColor ;
    vis[x][y]=1;



    dfsFloodFill(image,vis,x+1,y,newColor,oldColor,n,m);



    dfsFloodFill(image,vis,x-1,y,newColor,oldColor,n,m);




    dfsFloodFill(image,vis,x,y+1,newColor,oldColor,n,m);



    dfsFloodFill(image,vis,x,y-1,newColor,oldColor,n,m);



    vis[x][y]=0;

}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int oldColor = image[x][y];
    int i = image.size();
    int j = image[0].size();
    vector<vector<int>>vis(i,vector<int>(j,0));
    dfsFloodFill(image,vis,x,y,newColor,oldColor,i,j);
    return image;

}